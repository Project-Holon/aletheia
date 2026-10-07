/*
 * file:     script_work_p03.c
 * unit:     yes
 * function: func_02157A30, func_02157A58, func_02157A78, func_02157AC8
 * address:  0x02157A30
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02179D3C 0x02179D3C thumb ov015
 *   func_0203CEAC 0x0203CEAC arm
 *   func_02157960 0x02157960 thumb ov010
 *   func_021579B0 0x021579B0 thumb ov010
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D378  0x0203D378  arm
 *   func_0217998C  0x0217998C  thumb ov015
 *   func_02039C68 0x02039C68 arm
 */
struct Entry;
struct Link;
typedef unsigned char  u8;

typedef unsigned int u32;

extern int func_02179D3C(void);
extern int func_0203CEAC(int);
extern void func_02157960(int, int, int);
extern void func_021579B0(u8 *p);
extern struct Entry *func_020399A8(void);
extern u32 func_02039CB4(struct Link *p, u32 lo, u32 hi);
extern u32 func_0203D378(void);
extern void func_0217998C(int);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
void func_02157A30(int p);
void func_02157A58(int p);
void func_02157A78(u32 *p);
void func_02157AC8(int *p);

void func_02157A30(int p) { if (func_02179D3C()) func_0203CEAC(0); func_02157960(p, (int)func_021579B0, 0x102); }

void func_02157A58(int p) { func_0203CEAC(0); func_02157960(p, (int)func_021579B0, 0x10a); }


void func_02157A78(u32 *p)
{
    int k = 0x23;
    void *h = func_020399A8();

    if (func_02039CB4(h, 0x23, (u8)*p) != 0) {
        if (func_0203D378() != 0) {
            k = 0x12C;
            func_0217998C(k);
            k -= 0x19;
            func_02157960((int)p, (int)func_02157A30, k);
            return;
        }
        k += 0xF3;
        func_02157960((int)p, (int)func_02157A58, k);
    }
}

void func_02157AC8(int *p) { int k = 0x23; func_02039C68((struct Link *)func_020399A8(), k, (u8)p[0]); func_02157960((int)p, (int)func_02157A78, k + 0xfc); }
