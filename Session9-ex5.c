#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}
int main() {
    int *arr = NULL;
    int n = 0;
    int choice;
    int value, index, count, sum;
    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat trong mang\n");
        printf("5. In ra phan tu la so nguyen to va tinh tong\n");
        printf("6. Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &n);
                arr = (int *)malloc(n * sizeof(int));  
                printf("Nhap gia tri cac phan tu:\n");
                for (int i = 0; i < n; i++) {
                    printf("Phan tu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                if (n == 0) {
                    printf("Mang chua duoc nhap\n");
                } else {
                    printf("Cac phan tu trong mang: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                if (n == 0) {
                    printf("Mang chua duoc nhap\n");
                } else {
                    sum = 0;
                    printf("Cac phan tu chan trong mang: ");
                    for (int i = 0; i < n; i++) {
                        if (arr[i] % 2 == 0) {
                            printf("%d ", arr[i]);
                            sum += arr[i];
                        }
                    }
                    printf("\nTong cac phan tu chan: %d\n", sum);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("Mang chua duoc nhap\n");
                } else {
                    int max = arr[0];
                    int min = arr[0];
                    for (int i = 1; i < n; i++) {
                        if (arr[i] > max) 
						max = arr[i];
                        if (arr[i] < min) 
						min = arr[i];
                    }
                    printf("Gia tri lon nhat trong mang la: %d\n", max);
                    printf("Gia tri nho nhat trong mang la: %d\n", min);
                }
                break;
            case 5:
                if (n == 0) {
                    printf("Mang chua duoc nhap\n");
                } else {
                    sum = 0;
                    printf("Cac phan tu la so nguyen to trong mang la: ");
                    for (int i = 0; i < n; i++) {
                        if (is_prime(arr[i])) {
                            printf("%d ", arr[i]);
                            sum += arr[i];
                        }
                    }
                    printf("\nTong cac so nguyen to: %d\n", sum);
                }
                break;
            case 6:
                if (n == 0) {
                    printf("Mang chua duoc nhap\n");
                } else {
                    printf("Nhap so can tim: ");
                    scanf("%d", &value);
                    count = 0;
                    for (int i = 0; i < n; i++) {
                        if (arr[i] == value) {
                            count++;
                        }
                    }
                    printf("So %d xuat hien %d lan trong mang\n", value, count);
                }
                break;
            case 7:
                if (n == 0) {
                    printf("Mang chua duoc nhap\n");
                } else {
                    printf("Nhap vi tri can them phan tu (tu 1 den %d): ", n);
                    scanf("%d", &index);
                    if (index <= 0 || index > n) {
                        printf("Vi tri khong hop le\n");
                    } else {
                        n++;  
                        arr = (int *)realloc(arr, n * sizeof(int)); 
                        for (int i = n-1; i >= index-1; i--) {
                            arr[i] = arr[i-1];  
                        }
                        printf("Nhap gia tri phan tu moi: ");
                        scanf("%d", &arr[index-1]);
                        printf("Da them phan tu %d vao vi tri %d.\n", arr[index], index);
                    }
                }
                break;
            case 8:
                free(arr); 
                printf("Thoat chuong trinh\n");
                return 0;  
            default:
                printf("Lua chon khong hop le vui long chon lai\n");
                break;
        }
    }
    return 0;
}
