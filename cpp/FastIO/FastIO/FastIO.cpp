#include <jni.h>
#include <fstream>
#include <iostream>

extern "C" {

    // 读取文件内容为字节数组
    JNIEXPORT jbyteArray JNICALL Java_cn_langya_FastIO_load(JNIEnv* env, jobject obj, jstring filePath) {
        // 获取 Java 字符串
        const char* path = env->GetStringUTFChars(filePath, NULL);
        std::ifstream file(path, std::ios::binary | std::ios::ate);  // 打开文件，定位到末尾获取文件大小

        if (!file.is_open()) {
            env->ReleaseStringUTFChars(filePath, path);  // 释放资源
            return NULL;  // 文件打开失败，返回 null
        }

        std::streamsize size = file.tellg();  // 获取文件大小
        file.seekg(0, std::ios::beg);  // 重置文件指针回到开头

        // 创建字节数组
        jbyteArray byteArray = env->NewByteArray(size);
        if (byteArray == NULL) {
            env->ReleaseStringUTFChars(filePath, path);  // 释放资源
            return NULL;  // 内存分配失败，返回 null
        }

        // 读取文件内容到字节数组
        file.read(reinterpret_cast<char*>(env->GetByteArrayElements(byteArray, NULL)), size);
        env->ReleaseStringUTFChars(filePath, path);  // 释放资源
        return byteArray;  // 返回字节数组
    }

    // 保存字节数组到文件
    JNIEXPORT jboolean JNICALL Java_cn_langya_FastIO_save(JNIEnv* env, jobject obj, jstring filePath, jbyteArray data) {
        const char* path = env->GetStringUTFChars(filePath, NULL);
        std::ofstream file(path, std::ios::binary);  // 以二进制模式打开文件

        if (!file.is_open()) {
            env->ReleaseStringUTFChars(filePath, path);  // 释放资源
            return JNI_FALSE;  // 文件打开失败，返回 false
        }

        jsize length = env->GetArrayLength(data);  // 获取字节数组长度
        jbyte* byteArray = env->GetByteArrayElements(data, NULL);  // 获取字节数组内容

        // 写入字节数组到文件
        file.write(reinterpret_cast<char*>(byteArray), length);
        env->ReleaseByteArrayElements(data, byteArray, 0);  // 释放字节数组资源
        env->ReleaseStringUTFChars(filePath, path);  // 释放资源

        return JNI_TRUE;  // 成功保存文件，返回 true
    }
}
