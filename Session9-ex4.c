#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr = NULL;   
    int n = 0;         
    int choice;      
    int index, value; 
    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap so luong phan tu cua mang: ");
                scanf("%d", &n);
                arr = (int *)malloc(n * sizeof(int));
                printf("Nhap cac phan tu cua mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("Phan tu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                if (n == 0) {
                    printf("Mang chua duoc nhap\n");
                } else {
                    printf("Mang hien tai la: ");
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
                    n++;  
                    arr = (int *)realloc(arr, n * sizeof(int));  
                    printf("Nhap gia tri phan tu can them: ");
                    scanf("%d", &arr[n - 1]);  
                    printf("Da them phan tu %d vao mang\n", arr[n - 1]);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("Mang chua duoc nhap\n");
                } else {
                    printf("Nhap vi tri phan tu can sua (tu 1 den %d): ", n);
                    scanf("%d", &index);                   
                    if (index > 0 && index <= n) {
                        printf("Nhap gia tri moi cho phan tu %d: ", index);
                        scanf("%d", &value);
                        arr[index-1] = value;
                        printf("Da sua phan tu tai vi tri %d thanh %d.\n", index, value);
                    } else {
                        printf("Vi tri khong hop le\n");
                    }
                }
                break;
            case 5:
                if (n == 0) {
                    printf("Mang chua duoc nhap\n");
                } else {
                    printf("Nhap vi tri phan tu can xoa (tu 1 den %d): ", n);
                    scanf("%d", &index);
                    if (index > 0 && index <= n) {
                        for (int i = index-1; i < n - 1; i++) {
                            arr[i] = arr[i + 1];  
                        }
                        n--;  
                        arr = (int *)realloc(arr, n * sizeof(int)); 
                        printf("Da xoa phan tu tai vi tri %d.\n", index);
                    } else {
                        printf("Vi tri khong hop le\n");
                    }
                }
                break;
            case 6:
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
