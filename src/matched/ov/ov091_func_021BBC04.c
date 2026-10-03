/*
 * function: func_021BBC04
 * address: 0x021BBC04
 * packet: pkt_ov091_021BBC04
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B99E4 0x021B99E4 thumb ov091
 *   func_021BB43C 0x021BB43C thumb ov091
 *   func_021BBD98 0x021BBD98 thumb ov091
 *   func_02017E1C 0x02017E1C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021B99E4(void *, int);
extern int func_021BB43C(int *);
extern int func_021BBD98(int, int, int);
typedef unsigned int   u32;
extern u32 func_02017E1C(void *p, u32 id, u32 v);
#define APPEND(v) do { *(u16 *)(s + s[0] * 2 + 2) = (v); s[0]++; } while (0)
void func_021BBC04(u8 *p, u8 *s, int *items)
{
    int n, i;
    u8 j;
    int v;
    n = 0;
    while (items[n] != 16) {
        n++;
        if (n >= 8)
            break;
    }
    s[0] = 0;
    for (i = 0; i < n; i++) {
        switch (items[i]) {
        case 0: APPEND(0); break;
        case 1:
            for (j = 0; j < 4; j++) {
                if (func_021B99E4(*(void **)(p + 0x38), j))
                    APPEND(j + 16);
            }
            break;
        case 2:
            for (j = 0; j < 4; j++) {
                if (func_02017E1C(*(void **)(p + 0x38), j + 0x36, 0))
                    APPEND(j + 16);
            }
            break;
        case 3: APPEND(3); break;
        case 4: APPEND(4); break;
        case 5: APPEND(5); break;
        case 6: APPEND(6); break;
        case 7: APPEND(7); break;
        case 8:
            v = func_021BB43C(*(int **)(p + *(int *)(p + 0x2c) * 4 + 0x160));
            if (v == 6)
                APPEND(20);
            else if (v <= 5)
                APPEND(21);
            break;
        case 9: APPEND(9); break;
        case 10: APPEND(10); break;
        case 11: APPEND(11); break;
        case 12: APPEND(12); break;
        case 13: APPEND(13); break;
        case 14: APPEND(14); break;
        case 15: APPEND(15); break;
        }
    }
    for (n = 0; n < s[0]; n++) {
        u8 *entry;
        *(int *)(s + n * 12 + 0x14) = func_021BBD98((int)p, (int)s, *(u16 *)(s + n * 2 + 2));
        entry = s + n * 12;
        if (*(u16 *)(s + n * 2 + 2) >= 16 && *(u16 *)(s + n * 2 + 2) <= 19 && (*(int **)(p + 0x280))[0x34 / 4] != 5)
            *(u16 *)(entry + 0x18) = 0x35e0;
        else
            *(u16 *)(entry + 0x18) = 0x39e0;
        if (*(u16 *)(s + n * 2 + 2) == 6)
            *(int *)(entry + 0x1c) = 1;
        else
            *(int *)(entry + 0x1c) = 0;
    }
}
