#include <stdio.h> 
int main(){
	int index, value, n;
	int arr[n];
	printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
	printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
}
    printf("Nhap vi tri phan tu can sua (tu 1 den %d): ", n);
    scanf("%d", &index);                   
    if (index > 0 && index <= n) {
        printf("Nhap gia tri moi cho phan tu %d: ", index);
        scanf("%d", &value);
        arr[index-1] = value;
    } else {
        printf("Vi tri khong hop le\n");
 }   
 	printf("Mang sau khi sua la: ");
 	for(int i = 0;i<n; i++){
 		printf("%d", arr[i]);
	 }  
	return 0;
}  
   
   