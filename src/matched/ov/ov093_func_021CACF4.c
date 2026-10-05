/*
 * function: func_021CACF4
 * address: 0x021CACF4
 * packet: pkt_ov093_021CACF4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: the function is 546 bytes; the listed 740 bytes include two alignment
 *   bytes and twelve 16-byte linker veneers CAF18..CAFC8 (separate, not C).
 * note: 2026-10-05 P19L4: the old 12-byte DIFF was the sp+0x14/sp+0x18 slot swap of
 *   n and j. n declared u32 (was unsigned long) gives the original slots. Callee
 *   func_021B8D8C is declared int as in its matched definition (same bytes).
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021B99E0 0x021B99E0 thumb ov093
 *   func_021CAA24 0x021CAA24 thumb ov093
 *   func_021B98A4 0x021B98A4 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021B8C38 0x021B8C38 thumb ov093
 *   func_021CB174 0x021CB174 thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021CB1D4 0x021CB1D4 thumb ov093
 *   func_021CAF18 0x021CAF18 thumb ov093
 *   func_021CAF28 0x021CAF28 thumb ov093
 *   func_021CAF38 0x021CAF38 thumb ov093
 *   func_021CAF48 0x021CAF48 thumb ov093
 *   func_021CAF58 0x021CAF58 thumb ov093
 *   func_021CAF68 0x021CAF68 thumb ov093
 *   func_021CAF78 0x021CAF78 thumb ov093
 *   func_021CAF88 0x021CAF88 thumb ov093
 *   func_021CAF98 0x021CAF98 thumb ov093
 *   func_021CAFA8 0x021CAFA8 thumb ov093
 *   func_021CAFB8 0x021CAFB8 thumb ov093
 *   func_021CAFC8 0x021CAFC8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Record { u16 n0, n1; u8 ids[6]; };
extern u8 func_021D5440(u8 *);
extern int func_021B8D8C(void *, void *, u32);
extern u8 *func_021B99E0(int);
extern int func_021CAA24(u8 *, u8 *, int, int, int);
extern u8 *func_021B98A4(void *, int);
extern u32 func_021D78AC(u32);
extern u8 func_021B8C38(u32, u32);
extern void *func_021CB174(u8 *, u32, int);
extern u8 *func_021B9934(char *, int);
extern u8 func_021CB1D4(u8 *, u8 *, u8 *, u32);
extern void func_021CAF18(void *, void *);
extern void func_021CAF28(void *, void *);
extern void func_021CAF38(void *, void *);
extern void func_021CAF48(void *, void *);
extern void func_021CAF58(void *, void *);
extern void func_021CAF68(void *, void *);
extern void func_021CAF78(void *, void *);
extern void func_021CAF88(void *, void *);
extern void func_021CAF98(void *, void *);
extern void func_021CAFA8(void *, void *);
extern void func_021CAFB8(void *, void *);
extern void func_021CAFC8(void *, void *);
int func_021CACF4(u8 *p, u8 *a, u16 move, u8 *q, long id, void *out)
{
    u32 i, count;
    u32 n = func_021B8D8C(*(void **)(p + 4), *(void **)(p + 8), func_021D5440(a));
    u8 *b = func_021B99E0(n);
    int key = func_021CAA24((u8 *)p, q, (int)a, n, move);
    u8 selected;
    switch (*(u32 *)(q + 12)) {
    case 0:
        b = func_021B98A4(*(void **)(p + 8), key);
        break;
    case 3:
        b = func_021B98A4(*(void **)(p + 8), key);
        break;
    case 9:
        selected = func_021D78AC(*(u16 *)b);
        b = func_021B98A4(*(void **)(p + 8), ((struct Record *)b)->ids[selected]);
        break;
    case 5:
        for (i = 0; i < *(u16 *)b; i++)
            func_021CAF18(out, func_021B98A4(*(void **)(p + 8), b[4 + i]));
        return (u8)*(u16 *)b;
    case 4: {
        long j;
        i = 0;
        count = 0;
        for (; i < *(u16 *)b; i++) {
            func_021CAF28(out, func_021B98A4(*(void **)(p + 8), b[4 + i]));
            count++;
        }
        for (j = 0; (u32)j < *(u16 *)(b + 2); j++) {
            if (n != b[7 + j]) {
                func_021CAF38(out, func_021B98A4(*(void **)(p + 8), b[7 + j]));
                count++;
            }
        }
        return (u8)count;
    }
    case 8:
        func_021CAF48(out, a);
        for (i = 0; i < 3; i++) {
            selected = func_021B8C38(n, (u8)i);
            if (selected != n) func_021CAF58(out, func_021B98A4(*(void **)(p + 8), selected));
        }
        func_021CAF68(out, func_021CB174((u8 *)p, n, 0));
        func_021CAF78(out, func_021CB174((u8 *)p, n, 1));
        func_021CAF88(out, func_021CB174((u8 *)p, n, 2));
        return 6;
    case 7:
        if (id == 31) func_021CAF98(out, a);
        else func_021CAF98(out, (void *)func_021B9934(*(char **)(p + 8), id));
        return 1;
    case 1:
        func_021CAFA8(out, func_021B98A4(*(void **)(p + 8), key));
        return 1;
    case 2:
        func_021CAFB8(out, func_021B98A4(*(void **)(p + 8), key));
        return 1;
    case 13:
        if (id != 31) {
            b = (u8 *)func_021B9934(*(char **)(p + 8), id);
            break;
        }
        return 0;
    case 6: case 10: case 11: case 12: default:
        return 0;
    }
    if (b) {
        selected = func_021CB1D4((u8 *)p, a, q, func_021D5440(b));
        if (selected != 31) b = (u8 *)func_021B9934(*(char **)(p + 8), selected);
        func_021CAFC8(out, b);
        return 1;
    }
    return 0;
}
