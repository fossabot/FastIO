# FastIO
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FLangYa466%2FFastIO.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2FLangYa466%2FFastIO?ref=badge_shield)

## 超轻量高效的文件IO库 只支持Windows (x64) 用C++写的 (JNI)

# 使用 maven/gradle 导入
https://jitpack.io/#LangYa466/FastIO/-SNAPSHOT
---

## 快速开始
```java
    public static void main(String[] args) {
        byte[] data = FastIO.load("file.txt");
        if (data != null) {
            System.out.println("File Loaded. Data length: " + data.length);
        }

        boolean result = FastIO.save("newFile.txt", "Hello, World!".getBytes());
        System.out.println("File Saved: " + result);
    }
```


## License
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FLangYa466%2FFastIO.svg?type=large)](https://app.fossa.com/projects/git%2Bgithub.com%2FLangYa466%2FFastIO?ref=badge_large)