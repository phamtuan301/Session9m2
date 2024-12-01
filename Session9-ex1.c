#include <stdio.h>
int main() {
    int arr[100];           
    int currentlength = 0;  
    int n, value, addindex;
    printf("Nhap so luong phan tu cua mang (<=100): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    currentlength = n;  
    printf("\nNhap gia tri phan tu can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri can them (1 den %d): ", currentlength);
    scanf("%d", &addindex);
    if (addindex <= 0 || addindex > currentlength) {
        printf("Vi tri khong hop le\n");
    } else {
        if (addindex == currentlength) {
            arr[currentlength] = value;
            currentlength++;  
        } else {
            for (int i = currentlength; i > addindex; i--) {
                arr[i] = arr[i - 1];
            }
            arr[addindex-1] = value;  
            currentlength++;  
        }
        printf("\nMang sau khi them phan tu: ");
        for (int i = 0; i < currentlength; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
