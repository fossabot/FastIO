package cn.langya;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;

/**
 * @author LangYa466
 * @date 2025/5/11
 */
public class FastIO {
    static {
        try {
            String libName = "FastIO.dll";
            try (InputStream in = FastIO.class.getClassLoader().getResourceAsStream("FastIO.dll")) {
                if (in == null) {
                    throw new RuntimeException("无法找到 " + libName + " 资源文件");
                }

                File tempFile = File.createTempFile("FastIO", ".dll");
                tempFile.deleteOnExit();

                try (FileOutputStream out = new FileOutputStream(tempFile)) {
                    byte[] buffer = new byte[8192];
                    int bytesRead;
                    while ((bytesRead = in.read(buffer)) != -1) {
                        out.write(buffer, 0, bytesRead);
                    }
                }

                System.load(tempFile.getAbsolutePath());
            }
        } catch (Exception e) {
            throw new RuntimeException("加载 FastIO.dll 失败", e);
        }
    }

    public static native byte[] load(String filePath);
    public static native boolean save(String filePath, byte[] data);

    public static byte[] load(File file) {
        return load(file.getAbsolutePath());
    }

    public static boolean save(File file, byte[] data) {
        return save(file.getAbsolutePath(), data);
    }
}
