import java.util.concurrent.*;

public class ArrayCreator {
    public static void main(String[] args) {
        int totalArrays = 1_000_000;
        int sizeInMB = 1;

        ScheduledExecutorService scheduler = Executors.newScheduledThreadPool(1);

        Runnable task = new Runnable() {
            int count = 0;

            @Override
            public void run() {
                if (count >= totalArrays) {
                    scheduler.shutdown();
                    System.out.println("Finished creating " + totalArrays + " arrays.");
                    return;
                }
                byte[] arr = new byte[1024 * 1024 * sizeInMB]; // 1MB
                System.out.println("Created array #" + (count + 1) + " of size: " + arr.length + " bytes");
                count++;
            }
        };

        // Run the task every 1 second
        scheduler.scheduleAtFixedRate(task, 0, 1, TimeUnit.SECONDS);
    }
}
