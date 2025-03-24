#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define AUTO_LOCK_THRESHOLD 5

// Function prototypes
void initializeSystem(int rooms, int lights[], int temp[], int motion[], int lock[]);
void displayMenu();
void toggleLight(int rooms, int lights[]);
void readTemperature(int rooms, int temp[]);
void checkMotion(int rooms, int motion[]);
void lockUnlockSecurity(int rooms, int lock[]);
void analyzeHouseStatus(int rooms, int lights[], int temp[], int motion[], int lock[]);
int allLightsOn(int rooms, int lights[]);
void handleAutoLock(int rooms, int lock[], int *noMotionCount);

int main() {
    int numRooms;
    printf("Enter number of rooms: ");
    scanf("%d", &numRooms);

    if (numRooms <= 0 || numRooms > MAX_ROOMS) {
        printf("Invalid number of rooms! Max allowed is %d.\n", MAX_ROOMS);
        return 1;
    }

    // ✅ Allocate memory dynamically
    int *lights = (int *)malloc(numRooms * sizeof(int));
    int *temp = (int *)malloc(numRooms * sizeof(int));
    int *motion = (int *)malloc(numRooms * sizeof(int));
    int *lock = (int *)malloc(numRooms * sizeof(int));

    if (lights == NULL || temp == NULL || motion == NULL || lock == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    initializeSystem(numRooms, lights, temp, motion, lock);

    int choice;
    int noMotionCount = 0;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                toggleLight(numRooms, lights);
                break;
            case 2:
                readTemperature(numRooms, temp);
                break;
            case 3:
                checkMotion(numRooms, motion);
                break;
            case 4:
                lockUnlockSecurity(numRooms, lock);
                break;
            case 5:
                analyzeHouseStatus(numRooms, lights, temp, motion, lock);
                break;
            case 6:
                printf("\nExiting...\n");
                // ✅ Free allocated memory before exiting
                free(lights);
                free(temp);
                free(motion);
                free(lock);
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }

        // Handle auto-lock if no motion detected
        handleAutoLock(numRooms, lock, &noMotionCount);

        // Energy-saving suggestion
        if (allLightsOn(numRooms, lights)) {
            printf("⚠ All lights are ON! Consider turning some off to save energy.\n");
        }
    }
}

// ✅ Initialize system with default values
void initializeSystem(int rooms, int lights[], int temp[], int motion[], int lock[]) {
    srand(time(0));
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0; // Lights OFF
        temp[i] = rand() % 11 + 20; // Temperature between 20°C and 30°C
        motion[i] = 0; // No motion detected initially
        lock[i] = 1; // Locked by default
    }
    printf("\nSystem initialized.\n");
}

// ✅ Display menu
void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

// ✅ Toggle light status
void toggleLight(int rooms, int lights[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);

    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }

    lights[room - 1] = !lights[room - 1];
    printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
}

// ✅ Read temperature of a specific room
void readTemperature(int rooms, int temp[]) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", rooms);
    scanf("%d", &room);

    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }

    printf("Room %d temperature: %d°C\n", room, temp[room - 1]);

    // 🔥 Temperature Alert
    if (temp[room - 1] > 30) {
        printf("🚨 WARNING: High temperature in Room %d! Take action.\n", room);
    }
}

// ✅ Check motion status
void checkMotion(int rooms, int motion[]) {
    printf("\nMotion Sensor Status:\n");
    for (int i = 0; i < rooms; i++) {
        motion[i] = rand() % 2;
        printf("Room %d: %s\n", i + 1, motion[i] ? "Motion Detected" : "No Motion");
    }
}

// ✅ Lock/Unlock security system
void lockUnlockSecurity(int rooms, int lock[]) {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", rooms);
    scanf("%d", &room);

    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }

    lock[room - 1] = !lock[room - 1];
    printf("Room %d security is now %s.\n", room, lock[room - 1] ? "Locked" : "Unlocked");
}

// ✅ Display house status
void analyzeHouseStatus(int rooms, int lights[], int temp[], int motion[], int lock[]) {
    printf("\n===== House Status =====\n");
    for (int i = 0; i < rooms; i++) {
        printf("Room %d: Light %s, Temp %d°C, %s, %s\n",
            i + 1,
            lights[i] ? "ON" : "OFF",
            temp[i],
            motion[i] ? "Motion Detected" : "No Motion",
            lock[i] ? "Locked" : "Unlocked");
    }
}

// ✅ Suggest energy-saving if all lights are on
int allLightsOn(int rooms, int lights[]) {
    for (int i = 0; i < rooms; i++) {
        if (lights[i] == 0) {
            return 0;
        }
    }
    return 1;
}

// ✅ Auto-lock if no motion detected for 5 cycles
void handleAutoLock(int rooms, int lock[], int *noMotionCount) {
    int motionDetected = 0;
    for (int i = 0; i < rooms; i++) {
        if (lock[i] == 0) {
            motionDetected = 1;
            break;
        }
    }

    if (!motionDetected) {
        (*noMotionCount)++;
    } else {
        *noMotionCount = 0;
    }

    if (*noMotionCount >= AUTO_LOCK_THRESHOLD) {
        for (int i = 0; i < rooms; i++) {
            lock[i] = 1; // Lock all rooms
        }
        printf("\n🔒 All rooms locked automatically due to inactivity.\n");
        *noMotionCount = 0;
    }
}