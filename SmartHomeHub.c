#include <stdio.h>

// ==================== GLOBAL VARIABLES ====================

// Light
int lightStatus = 0;
int lightRoom = 0;   // 1=Bedroom1, 2=Bedroom2, 3=Kitchen, 4=LivingRoom

// Fan
int fanStatus = 0;
int fanSpeed = 0;    // 1=Slow, 2=Medium, 3=Fast
int fanRoom = 0;

// AC
int acStatus = 0;
int acTemp = 0;      // 16-30

// Window
int windowStatus = 0;  // 0=Closed, 1=Open, 2=Halfway
int windowMode = 0;    // 1=Manual, 2=Auto
int windowRoom = 0;

// ==================== FUNCTION DECLARATIONS ====================

void controlLight();
void controlFan();
void controlAC();
void controlWindow();
void showStatus();
int  selectRoom();
void printRoom(int room);

// ==================== ROOM SELECTOR ====================

int selectRoom() {
    int room;
    printf("  Select Room:\n");
    printf("  1. Bedroom 1\n");
    printf("  2. Bedroom 2\n");
    printf("  3. Kitchen\n");
    printf("  4. Living Room\n");
    printf("  Enter choice: ");
    scanf("%d", &room);
    if (room < 1 || room > 4) {
        printf("  Invalid room! Setting to Bedroom 1.\n");
        room = 1;
    }
    return room;
}

void printRoom(int room) {
    switch (room) {
        case 1: printf("Bedroom 1");   break;
        case 2: printf("Bedroom 2");   break;
        case 3: printf("Kitchen");     break;
        case 4: printf("Living Room"); break;
        default: printf("Not Set");    break;
    }
}

// ==================== CONTROL FUNCTIONS ====================

void controlLight() {
    int opt;
    printf("\n--- LIGHT CONTROL ---\n");
    printf("1. ON\n2. OFF\n");
    printf("Enter choice: ");
    scanf("%d", &opt);
    switch (opt) {
        case 1:
            lightStatus = 1;
            lightRoom = selectRoom();
            printf("Light turned ON in ");
            printRoom(lightRoom);
            printf(".\n");
            break;
        case 2:
            lightStatus = 0;
            printf("Light turned OFF.\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void controlFan() {
    int opt;
    printf("\n--- FAN CONTROL ---\n");
    printf("1. ON\n2. OFF\n");
    printf("Enter choice: ");
    scanf("%d", &opt);
    switch (opt) {
        case 1:
            fanStatus = 1;
            printf("  Select Speed:\n  1. Slow\n  2. Medium\n  3. Fast\n  Enter choice: ");
            scanf("%d", &fanSpeed);
            if (fanSpeed < 1 || fanSpeed > 3) {
                printf("  Invalid speed! Setting to 1.\n");
                fanSpeed = 1;
            }
            fanRoom = selectRoom();
            printf("Fan ON | Speed: %d | Room: ", fanSpeed);
            printRoom(fanRoom);
            printf(".\n");
            break;
        case 2:
            fanStatus = 0;
            fanSpeed = 0;
            printf("Fan turned OFF.\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void controlAC() {
    int opt;
    printf("\n--- AC CONTROL ---\n");
    printf("1. ON\n2. OFF\n");
    printf("Enter choice: ");
    scanf("%d", &opt);
    switch (opt) {
        case 1:
            acStatus = 1;
            printf("  Enter Temperature (16-30): ");
            scanf("%d", &acTemp);
            if (acTemp < 16 || acTemp > 30) {
                printf("  Invalid temp! Setting to 24.\n");
                acTemp = 24;
            }
            printf("AC turned ON at %d C.\n", acTemp);
            break;
        case 2:
            acStatus = 0;
            acTemp = 0;
            printf("AC turned OFF.\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void controlWindow() {
    int opt, pos;
    printf("\n--- WINDOW CONTROL ---\n");
    printf("1. Manual Mode\n2. Auto Mode (sunlight based)\n");
    printf("Enter choice: ");
    scanf("%d", &opt);
    switch (opt) {
        case 1:
            windowMode = 1;
            printf("  1. Open\n  2. Close\n  3. Halfway\n  Enter choice: ");
            scanf("%d", &pos);
            switch (pos) {
                case 1: windowStatus = 1; break;
                case 2: windowStatus = 0; break;
                case 3: windowStatus = 2; break;
                default:
                    printf("  Invalid! Setting to Closed.\n");
                    windowStatus = 0;
            }
            windowRoom = selectRoom();
            printf("Window set | Room: ");
            printRoom(windowRoom);
            printf(".\n");
            break;
        case 2:
            windowMode = 2;
            windowStatus = 1;
            windowRoom = selectRoom();
            printf("Window AUTO mode ON in ");
            printRoom(windowRoom);
            printf(". Adjusting based on sunlight.\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// ==================== STATUS DISPLAY ====================

void showStatus() {
    printf("\n========== SMART HOME STATUS ==========\n");

    printf("LIGHT  : %s | Room: ", lightStatus ? "ON " : "OFF");
    printRoom(lightRoom); printf("\n");

    printf("FAN    : %s | Speed: %d | Room: ", fanStatus ? "ON " : "OFF", fanSpeed);
    printRoom(fanRoom); printf("\n");

    printf("AC     : %s | Temp: %d C\n", acStatus ? "ON " : "OFF", acTemp);

    printf("WINDOW : ");
    switch (windowStatus) {
        case 0: printf("CLOSED  "); break;
        case 1: printf("OPEN    "); break;
        case 2: printf("HALFWAY "); break;
    }
    printf("| Mode: %s | Room: ", windowMode == 1 ? "Manual" : windowMode == 2 ? "Auto" : "N/A");
    printRoom(windowRoom); printf("\n");

    printf("========================================\n");
}

// ==================== MAIN ====================

int main() {
    int choice;
printf("========================================\n");
printf("       WELCOME TO SMART HOME HUB        \n");
printf("          by Divya Mangtani             \n");
printf("========================================\n");

    do {
        printf("\n=== MAIN MENU ===\n");
        printf("1. Light\n");
        printf("2. Fan\n");
        printf("3. AC\n");
        printf("4. Window\n");
        printf("5. View Status\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: controlLight();  break;
            case 2: controlFan();    break;
            case 3: controlAC();     break;
            case 4: controlWindow(); break;
            case 5: showStatus();    break;
            case 6: printf("\nGoodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}