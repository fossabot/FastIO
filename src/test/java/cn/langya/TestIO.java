package cn.langya;

/**
 * @author LangYa466
 * @date 2025/5/11
 */
public class TestIO {
    public static void main(String[] args) {
        byte[] data = FastIO.load("file.txt");
        if (data != null) {
            System.out.println("File Loaded. Data length: " + data.length);
        }

        boolean result = FastIO.save("newFile.txt", "Hello, World!".getBytes());
        System.out.println("File Saved: " + result);
    }
}
