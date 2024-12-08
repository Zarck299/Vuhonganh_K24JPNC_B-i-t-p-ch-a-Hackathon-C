#include<stdio.h>
	#include <stdio.h>

int main() {
    int array[100], n = 0;
    int choice,pos;
    int countPerfect = 0;
    int countPrime = 0;
	int value, found = 0;
	int unique[100], u = 0;
	int even[100], odd[100], e = 0, o = 0;
    printf("MENU\n");
    printf("1. Nhap so phan tu va gia tri phan tu trong mang\n");
    printf("2. In mang ra man hinh duoi dang: arr[0]=...;arr[1]=...\n");
    printf("3. Dem so luong so hoan hao\n");
    printf("4. Dem so luong so nguyen to\n");
    printf("5. Tim gia tri lon thu 2\n");
    printf("6. Tim gia tri nho thu 2\n");
    printf("7. Them phan tu tai vi tri\n");
    printf("8. Xoa phan tu tai vi tri\n");
    printf("9. Sap xep mang tang dan (thao tac chen)\n");
    printf("10. Sap xep mang theo giam dan (thao tac chen)\n");
    printf("11. Tim kiem phan tu trong mang (tim kiem nhi phan)\n");
    printf("12. Xoa cac phan tu trung lap va in cac phan tu duy nhat\n");
    printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
    printf("14. Dao nguoc mang\n");
    printf("15. Thoat\n");
    if (choice>0 && choice<15){
	    printf("Lua chon cua ban: %d\n");
		scanf("%d", &choice);
	}
    switch(choice) {
    	case 1:
	            printf("Nhap so phan tu trong mang: ");
	            scanf("%d", &n);
	            if (n < 0) {
		        	printf("So phan tu khong hop le!! Vui lonn nhap lai: %d\n");
		        	scanf("%d", &n);
        		}
        		for(int i=0; i<n; i++){
        			printf("Nhap phan tu thu %d cua mang: \n",i);
        			scanf("%d", array[i]);
				}
				break;
		case 2:
				if (n == 0) {
                    printf("Mang chua co phan tu nao.\n");
                } else {
                    printf("Cac phan tu trong mang la: ");
                    for (int i = 0; i < n; i++) {
                        printf("array[%d] = %d; ", i, array[i]);
                    }
                    printf("\n");
                }
                break;
		case 3:
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j < array[i]; j++) {
                    if (array[i] % j == 0) {
                        sum += j;
                    }
                }
                if (sum == array[i]) {
                    countPerfect++;
                }
                printf("So luong so hoan hao: %d\n", countPerfect);
            }
            break;
      	case 4:
            for (int i = 0; i < n; i++) {
                int isPrime = 1;
                if (array[i] < 2) isPrime = 0;
                for (int j = 2; j * j <= array[i]; j++) {
                    if (array[i] % j == 0) {
                        isPrime = 0;
                        break;
                    }
                }
                if (isPrime) countPrime++;
            }
            printf("So luong so nguyen to: %d\n", countPrime);
            break;
        case 5:
            if (n < 2) {
                printf("Khong du phan tu de tim gia tri lon thu 2\n");
            } 
			else {
                int max = array[0], secondMax = -1e9;
                for (int i = 0; i < n; i++) {
                    if (array[i] > max) {
                        secondMax = max;
                        max = array[i];
                    } else if (array[i] > secondMax && array[i] != max) {
                        secondMax = array[i];
                    }
                }
                printf("Gia tri lon thu 2: %d\n", secondMax);
            }
            break;
        case 6:
            if (n < 2) {
                printf("Khong du phan tu de tim gia tri nho thu 2\n");
            } else {
                int min = array[0], secondMin = 1e9;
                for (int i = 0; i < n; i++) {
                    if (array[i] < min) {
                        secondMin = min;
                        min = array[i];
                    } else if (array[i] < secondMin && array[i] != min) {
                        secondMin = array[i];
                    }
                }
                printf("Gia tri nho thu 2: %d\n", secondMin);
            }
            break;
        case 7:
            if (n < 100) {
                int value, pos;
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri can them (0-%d): ", n);
                scanf("%d", &pos);
                for (int i = n; i > pos; i--) {
                    array[i] = array[i - 1];
                }
                array[pos] = value;
                n++;
            } else {
                printf("Khong the them, mang da day.\n");
            }
            break;
        case 8:
            printf("Nhap vi tri can xoa (0-%d): ", n - 1);
            scanf("%d", &pos);
            for (int i = pos; i < n - 1; i++) {
                array[i] = array[i + 1];
            }
            n--;
            break;
        case 9:
            for (int i = 1; i < n; i++) {
                int key = array[i];
                int j = i - 1;
                while (j >= 0 && array[j] > key) {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = key;
            }
            printf("Mang sau khi sap xep tang dan.\n");
            break;
        case 10:
            for (int i = 1; i < n; i++) {
                int key = array[i];
                int j = i - 1;
                while (j >= 0 && array[j] < key) {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = key;
            }
            printf("Mang sau khi sap xep giam dan.\n");
            break;
        case 11:
            printf("Nhap gia tri can tim: ");
            scanf("%d", &value);
            for (int i = 0; i < n; i++) {
                if (array[i] == value) {
                    printf("Gia tri %d o vi tri %d\n", value, i);
                    found = 1;
                }
            }
            if (!found) printf("Khong tim thay gia tri %d\n", value);
            break;
        case 12:
            for (int i = 0; i < n; i++) {
                int isDuplicate = 0;
                for (int j = 0; j < u; j++) {
                    if (array[i] == unique[j]) {
                        isDuplicate = 1;
                        break;
                    }
                }
                if (!isDuplicate) unique[u++] = array[i];
            }
            printf("Cac phan tu duy nhat: ");
            for (int i = 0; i < u; i++) {
                printf("%d ", unique[i]);
            }
            printf("\n");
            break;
        case 13:
            for (int i = 0; i < n; i++) {
                if (array[i] % 2 == 0) even[e++] = array[i];
                else odd[o++] = array[i];
            }
            printf("So chan dung truoc: ");
            for (int i = 0; i < e; i++) printf("%d ", even[i]);
            printf("So le dung sau: ");
            for (int i = 0; i < o; i++) printf("%d ", odd[i]);
            printf("\n");
        	break;
        case 14:
            for (int i = 0; i < n / 2; i++) {
                int temp = array[i];
                array[i] = array[n - i - 1];
                array[n - i - 1] = temp;
            }
            printf("Mang sau khi dao nguoc.\n");
        	break;
        case 15:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
        
    	}
    	while(n!=16);
    		return 0;
    }

