#include <stdio.h>
#include <stdlib.h>

struct HealthParameters {
    int bp;
    int heartRate;
    float Glucose;
};

int main() {
    struct HealthParameters params;
    int choice;

    while (1) {
        printf("\nHealth Monitoring System\n");
        printf("1. Record Health Parameters\n");
        printf("2. Display Health Parameters\n");
        printf("3. Save Health Parameters to File\n");
        printf("4. Load Health Parameters from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter blood pressure: ");
                scanf("%d", &params.bp);
                printf("Enter heart rate: ");
                scanf("%d", &params.heartRate);
                printf("Enter blood glucose level: ");
                scanf("%f", &params.Glucose);
                break;
            case 2:
                printf("\nHealth Parameters:\n");
                printf("Blood Pressure: %d\n", params.bp);
                printf("Heart Rate: %d\n", params.heartRate);
                printf("Blood Glucose Level: %.2f\n", params.Glucose);
                break;
            case 3: {
                FILE *file = fopen("health_parameters.txt", "w");
                if (file == NULL) {
                    printf("Error in opening file.\n");
                    break;
                }
                fprintf(file, "%d %d %.2f\n", params.bp, params.heartRate, params.Glucose);
                fclose(file);
                printf("Health parameters saved to file.\n");
                break;
            }
            case 4: {
                FILE *file = fopen("health_parameters.txt", "r");
                if (file == NULL) {
                    printf("Error in opening file.\n");
                    break;
                }
                fscanf(file, "%d %d %f", &params.bp, &params.heartRate, &params.Glucose);
                fclose(file);
                printf("Health parameters loaded from file.\n");
                break;
            }
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}