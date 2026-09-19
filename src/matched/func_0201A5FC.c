/*
 * function: func_0201A5FC
 * address:  0x0201A5FC
 * packet:   pkt_0201A5FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200AE54   0x0200AE54  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0201AB28   0x0201AB28  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_0201A26C   0x0201A26C  thumb
 *   func_02019DA4   0x02019DA4  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A5FC.c  *       --func func_0201A5FC --addr 0x0201A5FC --cc 1.1p1 --thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int   func_0200AE54(void *a0, int k);
extern int   func_0201AA18(void *a1);
extern void *func_0201AB28(void *a1, int n);
extern u32   func_02017E1C(void *p, int a, int b);
extern int   func_0201A26C(void *a0, u32 v);
extern u32   func_02019DA4(void *a0, void *p);

int func_0201A5FC(void *a0, void *a1, u8 *a2, char *a3, u32 *a4)
{
    u8 count = 0;
    u32 arr5c[6] = {0};
    u32 arr44[6] = {0};
    u32 arr2c[6] = {0};
    u8 i;
    int flag;
    u32 acc;
    void *p;
    u32 v18;
    u32 v14;
    u32 v10;
    u8 n;
    u8 j;
    u32 v6;
    u32 k1;
    u8 k;
    u32 k2;
    u32 r;
    int found;

    acc = 0;
    v10 = (u32)func_0200AE54(a0, 6);

    if (a3 != 0)
        *a3 = 0;
    if (a4 != 0)
        *a4 = 0;

    for (i = 0; i < 6; i++) {
        if (a2[i] == 0)
            continue;
        n = (u8)(a2[i] - 1);
        if ((int)n >= func_0201AA18(a1))
            continue;
        p = func_0201AB28(a1, n);
        v18 = func_02017E1C(p, 5, 0);
        v6 = func_02017E1C(p, 6, 0);
        v14 = (u32)func_0201A26C(a0, func_02017E1C(p, 0x9e, 0));
        r = func_02019DA4(a0, p);
        if (r != 0) {
            if (a4 != 0)
                *a4 |= r;
            continue;
        }
        flag = 1;
        for (j = 0; j < count; j++) {
            if (func_0200AE54(a0, 7) == 0 && v18 == arr5c[j]) {
                flag = 0;
                if (a4 != 0)
                    *a4 |= 8;
                break;
            }
            if (func_0200AE54(a0, 8) == 0 && v6 != 0 && v6 == arr2c[j]) {
                flag = 0;
                if (a4 != 0)
                    *a4 |= 0x10;
                break;
            }
        }
        if (flag == 0)
            continue;
        if (v10 != 0 && (u32)(acc + v14) > v10) {
            if (a4 != 0)
                *a4 |= 0x100;
            continue;
        }
        if (a3 != 0)
            a3[count] = (char)(n + 1);
        arr5c[count] = v18;
        arr44[count] = func_02017E1C(p, 0x6f, 0);
        arr2c[count] = v6;
        acc = (u16)(acc + (u16)v14);
        count = (u8)(count + 1);
        if ((int)count < func_0200AE54(a0, 3))
            continue;
        if (a4 != 0 && count < 6 && a2[count] != 0)
            *a4 |= 1;
        break;
    }

    if ((int)count >= func_0200AE54(a0, 2)) {
        k1 = (u32)func_0200AE54(a0, 0xb);
        found = 1;
        if (k1 != 0) {
            k2 = (u32)func_0200AE54(a0, 0xc);
            found = 0;
            for (k = 0; k < count; k++) {
                if (k1 == arr5c[k] && k2 == arr44[k]) {
                    found = 1;
                    break;
                }
            }
        }
        if (found == 1)
            return 1;
        if (a4 != 0)
            *a4 |= 0x80;
    } else {
        if (a4 != 0)
            *a4 |= 1;
    }
    return 0;
}
