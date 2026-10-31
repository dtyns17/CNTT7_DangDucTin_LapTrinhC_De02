#include <stdio.h>
#include <string.h>

struct Thuoc {
    int maThuoc;
    char tenThuoc[50];
    int soLuong;
    float donGia;
};

void xoaXuongDong(char str[]) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

int timThuocTheoMa(struct Thuoc ds[], int n, int ma) {
    for (int i = 0; i < n; i++) {
        if (ds[i].maThuoc == ma) {
            return i;
        }
    }
    return -1;
}

int themThuoc(struct Thuoc ds[], int n) {
    if (n >= 50) {
        printf("Danh sach da day!\n");
        return n;
    }
    int ma;
    printf("Nhap ma thuoc: ");
    scanf("%d", &ma);
    while (getchar() != '\n');

    ds[n].maThuoc = ma;
    printf("Nhap ten thuoc: ");
    fgets(ds[n].tenThuoc, sizeof(ds[n].tenThuoc), stdin);
    xoaXuongDong(ds[n].tenThuoc);

    do {
        printf("Nhap so luong: ");
        scanf("%d", &ds[n].soLuong);
        if (ds[n].soLuong < 0) {
            printf("So luong phai >= 0!\n");
        }
    } while (ds[n].soLuong < 0);

    do {
        printf("Nhap don gia: ");
        scanf("%f", &ds[n].donGia);
        if (ds[n].donGia <= 0) {
            printf("Don gia phai > 0!\n");
        }
    } while (ds[n].donGia <= 0);
    while (getchar() != '\n');
    printf("Them thuoc thanh cong!\n");
    return n + 1;
}

void hienThiDanhSach(struct Thuoc ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong!\n");
        return;
    }
    printf("%-10s %-25s %-10s %-15s %-15s\n", "Ma thuoc", "Ten Thuoc", "So luong", "Don gia", "Thanh tien");
    for (int i = 0; i < n; i++) {
        long long thanhTien = (long long) ds[i].donGia * ds[i].soLuong;
        long long donGiaNguyen =  ds[i].donGia;
        printf("%-10d %-25s %-10d %-15lld %-15lld\n", ds[i].maThuoc, ds[i].tenThuoc, ds[i].soLuong, donGiaNguyen, thanhTien);
    }
}

void capNhatThuoc(struct Thuoc ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong!\n");
        return;
    }
    int ma;
    printf("Nhap ma thuoc can sua: ");
    scanf("%d", &ma);
    while (getchar() != '\n');

    int index = timThuocTheoMa(ds, n, ma);
    if (index == -1) {
        printf("Khong tim thay thuoc!\n");
        return;
    }
    printf("Nhap ten thuoc moi: ");
    fgets(ds[index].tenThuoc, sizeof(ds[index].tenThuoc), stdin);
    xoaXuongDong(ds[index].tenThuoc);

    do {
        printf("Nhap so luong moi: ");
        scanf("%d", &ds[index].soLuong);
        if (ds[index].soLuong < 0) {
            printf("So luong phai >= 0!\n");
        }
    } while (ds[index].soLuong < 0);

    do {
        printf("Nhap don gia moi: ");
        scanf("%f", &ds[index].donGia);
        if (ds[index].donGia <= 0) {
            printf("Don gia phai > 0!\n");
        }
    } while (ds[index].donGia <= 0);
    while (getchar() != '\n');
    printf("Cap nhat thanh cong!\n");
}

int xoaThuoc(struct Thuoc ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong!\n");
        return n;
    }
    int ma;
    printf("Nhap ma thuoc can xoa: ");
    scanf("%d", &ma);
    while (getchar() != '\n');

    int index = timThuocTheoMa(ds, n, ma);
    if (index == -1) {
        printf("Khong tim thay thuoc!\n");
        return n;
    }
    for (int i = index; i < n - 1; i++) {
        ds[i] = ds[i + 1];
    }
    printf("Xoa thanh cong!\n");
    return n - 1;
}

void timThuocTheoTen(struct Thuoc ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong!\n");
        return;
    }
    char tenTimKiem[50];

}

int main() {
    struct Thuoc danhSach[50];
    int soLuongHienTai = 0;
    int chon;

    do {
        printf("====== QUAN LY THUOC ======\n");
        printf("1. Them thuoc\n");
        printf("2. Hien thi danh sach thuoc\n");
        printf("3. Cap nhat thuoc theo ma\n");
        printf("4. Xoa thuoc theo ma\n");
        printf("5. Tim thuoc theo ten\n");
        printf("6. Thong ke kho hang\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chon);
        switch (chon) {
            case 1:
                soLuongHienTai = themThuoc(danhSach, soLuongHienTai);
                break;
            case 2:
                hienThiDanhSach(danhSach, soLuongHienTai);
                break;
            case 3:
                capNhatThuoc(danhSach, soLuongHienTai);
                break;
            case 4:
                xoaThuoc(danhSach, soLuongHienTai);
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (chon != 0);
    return 0;
}
