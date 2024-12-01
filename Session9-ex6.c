#include <stdio.h>
int main() {
    int matrix[100][100];  
    int rows, cols;        
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu trong mang theo ma tran\n");
        printf("3. In gia tri cac phan tu la le va tinh tong\n");
        printf("4. In ra cac phan tu tren duong bien va tinh tich\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("6. In ra cac phan tu nam tren duong cheo phu\n");
        printf("7. In ra dong co tong cac phan tu la lon nhat\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);       
        switch(choice) {
            case 1:
                printf("Nhap so dong cua ma tran: ");
                scanf("%d", &rows);
                printf("Nhap so cot cua ma tran: ");
                scanf("%d", &cols);
                printf("Nhap cac phan tu cua ma tran:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("Phan tu [%d][%d]: ", i + 1, j + 1);
                        scanf("%d", &matrix[i][j]);
                    }
                }
                break;
            case 2:
                printf("\nMa tran:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("%d ", matrix[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                printf("\nCac phan tu la le trong ma tran: ");
                int sumOdd = 0;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (matrix[i][j] % 2 != 0) {
                            printf("%d ", matrix[i][j]);
                            sumOdd += matrix[i][j];
                        }
                    }
                }
                printf("\nTong cac phan tu le: %d\n", sumOdd);
                break;
            case 4:
                printf("\nCac phan tu tren duong bien: ");
                int productBorder = 1;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                            printf("%d ", matrix[i][j]);
                            productBorder *= matrix[i][j];
                        }
                    }
                }
                printf("\nTich cac phan tu tren duong bien: %d\n", productBorder);
                break;
            case 5:
                printf("\nCac phan tu tren duong cheo chinh: ");
                for (int i = 0; i < rows && i < cols; i++) {
                    printf("%d ", matrix[i][i]);
                }
                printf("\n");
                break;
            case 6:
                printf("\nCac phan tu tren duong cheo phu: ");
                for (int i = 0; i < rows && i < cols; i++) {
                    printf("%d ", matrix[i][cols - i - 1]);
                }
                printf("\n");
                break;
            case 7:
                printf("\nDong co tong lon nhat: ");
                int maxSum = -1;
                int maxRow = -1;
                for (int i = 0; i < rows; i++) {
                    int rowSum = 0;
                    for (int j = 0; j < cols; j++) {
                        rowSum += matrix[i][j];
                    }
                    if (rowSum > maxSum) {
                        maxSum = rowSum;
                        maxRow = i;
                    }
                }
                for (int j = 0; j < cols; j++) {
                    printf("%d ", matrix[maxRow][j]);
                }
                printf("\n");
                break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le vui long nhap lai\n");
        }
    } while (choice != 8);
    return 0;
}
