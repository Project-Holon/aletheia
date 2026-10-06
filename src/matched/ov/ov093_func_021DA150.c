/*
 * function: func_021DA150
 * address: 0x021DA150
 * packet: pkt_ov093_021DA150
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021DA2D0 0x021DA2D0 thumb ov093
 *   func_021DA2E0 0x021DA2E0 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   func_021B9A6C 0x021B9A6C thumb ov093
 *   func_021C8010 0x021C8010 thumb ov093
 *   func_021C815C 0x021C815C thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
#include "../include/Obj06254.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int);
extern u16 func_021C7D00(void *, int);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021DA2D0(u16);
extern int func_021DA2E0(u16);
extern u32 func_021D78AC(u32);
extern u8 func_021D5440(u8 *p);
extern int func_021B9A24(u32 a, u32 b);
extern int func_021B9A6C(int a, u32 b);
extern int func_021C8010(u8 *p, unsigned int v);
extern int func_021C815C(int *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *, void *);
void func_021DA150(int a, void *b, int c, int *d)
{
    u8 buf[3];
    u8 selected[3];
    u8 chosen;
    u32 move;
    u8 active;
    u8 count, i, choice;
    u32 n;
    u16 mask;
    int slot;
    void *q;
    int candidate;
    u8 *p;
    active = func_021D775C(2);
    chosen = 31;
    move = 0;
    if (active == c) {
        mask = func_021C7D00(b, c);
        n = func_021C7F68(b, (u16)(mask | 0x100), buf);
        for (count = 0, i = 0; i < n; i++) {
            if (!func_021DA2D0((u16)func_021D59B4(func_021C7CF4(b, buf[i]), 16))) selected[count++] = buf[i];
        }
        if (count != 0) {
            choice = count == 1 ? 0 : func_021D78AC(count);
            q = func_021C7CF4(b, selected[choice]);
            move = func_021D59B4(q, 16);
            chosen = func_021D5440(q);
        } else {
            *d = 1;
        }
    } else if (!func_021B9A24(active, c) && *d == 1) {
        slot = func_021C8010(b, active);
        mask = func_021C7D00(b, c);
        if (slot != 6 && (func_021C815C(b) != 2 || func_021B9A6C(mask, slot))) {
            candidate = func_021D59B4(func_021C7CF4(b, active), 16);
            if (!func_021DA2E0((u16)candidate)) { move = candidate; chosen = active; }
        }
    }
    if (move != 0 && c != 31) {
        p = func_021C88A4(b, 31, c);
        p[6] = c;
        ((struct Obj06254 *)p)->f4 = move;
        p[8] = 1;
        ((struct Obj06254 *)p)->f0 |= 1 << 23;
        func_021C8838(p + 12, 2, 0x17d);
        func_021C8860((struct S *)(p + 12), chosen);
        func_021C8860((struct S *)(p + 12), ((struct Obj06254 *)p)->f4);
        func_021C88C8(b, p);
    }
}
