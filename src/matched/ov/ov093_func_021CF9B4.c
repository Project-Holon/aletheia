/*
 * function: func_021CF9B4
 * address: 0x021CF9B4
 * packet: pkt_ov093_021CF9B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021B8D38 0x021B8D38 thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021CFAC4 0x021CFAC4 thumb ov093
 *   func_021CFADC 0x021CFADC thumb ov093
 *   func_021CFB8C 0x021CFB8C thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *p);
extern int func_021B8D8C(void *, void *, u32);
extern u8 func_021B8D38(void *, int, u16, u8 *);
extern u8 *func_021B9934(void *, int);
extern int func_021D59B4(u8 *p, int k);
extern int func_021CFAC4(u8 *, void *);
extern int func_021CFADC(u8 *, void *);
extern int func_021CFB8C(u8 *, void *);
extern int func_021D62C4(void *, int);
u32 func_021CF9B4(u8 *g, void *m, u8 *a, u16 *b)
{
    u8 buf[4];
    u8 n;
    u8 i;
    u8 *q;
    u16 k;
    n = func_021B8D38(*(void **)g, *(int *)(g + 4), func_021B8D8C(*(void **)g, *(void **)(g + 4), func_021D5440(m)) | 0x100, buf);
    for (i = 0; i < n; i++) {
        q = func_021B9934(*(void **)(g + 4), buf[i]);
        k = func_021D59B4(q, 0x11);
        func_021D5440(q);
        if (k == 0x17 && func_021CFAC4(g, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
        if (k == 0x47 && func_021CFADC(g, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
        if (k == 0x2a && func_021CFB8C(g, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
    }
    if (func_021D62C4(m, 0x16) || func_021D62C4(m, 8) || func_021D62C4(m, 0x15)) {
        *a = func_021D5440(m);
        *b = 0;
        return 3;
    }
    return 4;
}
