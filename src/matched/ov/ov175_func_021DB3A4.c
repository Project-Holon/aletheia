/*
 * function: func_021DB3A4
 * address:  0x021DB3A4
 * packet:   pkt_021DB3A4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD02C  0x021DD02C  thumb
 *   func_021DD034  0x021DD034  thumb
 *   func_021DD038  0x021DD038  thumb
 *   func_021DD040  0x021DD040  thumb
 *   func_021DB7C0  0x021DB7C0  thumb
 *   func_021DBA00  0x021DBA00  thumb
 *   func_021DBB00  0x021DBB00  thumb
 *   func_021DBB54  0x021DBB54  thumb
 *   func_021DBBAC  0x021DBBAC  thumb
 *   d_021E2DF4     0x021E2DF4  data
 *   d_021E2DEC     0x021E2DEC  data
 *   d_021E2DF0     0x021E2DF0  data
 *
 * Selects a request kind 0..4: stores the table and its count at +0x194/+0x198 and the step callback at +0x17c, after resetting the step word at +0x12c and storing the two arguments.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef void (*StepFn)(void);

extern char *func_021DD02C(void);
extern u32 func_021DD034(void);
extern char *func_021DD038(void);
extern u32 func_021DD040(void);
extern void func_021DB7C0(void);
extern void func_021DBA00(void);
extern void func_021DBB00(void);
extern void func_021DBB54(void);
extern void func_021DBBAC(void);
extern char d_021E2DF4[];
extern char d_021E2DEC[];
extern char d_021E2DF0[];

void func_021DB3A4(char *obj, u32 target, int kind, u32 arg)
{
    *(u32 *)(obj + 0x12c) = 0;
    *(u32 *)(obj + 0x178) = arg;
    *(u32 *)(obj + 0x1b0) = target;
    switch (kind) {
    case 0:
        *(char **)(obj + 0x194) = func_021DD02C();
        *(u32 *)(obj + 0x198) = func_021DD034();
        *(StepFn *)(obj + 0x17c) = func_021DB7C0;
        break;
    case 1:
        *(char **)(obj + 0x194) = func_021DD038();
        *(u32 *)(obj + 0x198) = func_021DD040();
        *(StepFn *)(obj + 0x17c) = func_021DBA00;
        break;
    case 2:
        *(char **)(obj + 0x194) = d_021E2DF4;
        *(u32 *)(obj + 0x198) = 1;
        *(StepFn *)(obj + 0x17c) = func_021DBB00;
        break;
    case 3:
        *(char **)(obj + 0x194) = d_021E2DEC;
        *(u32 *)(obj + 0x198) = 1;
        *(StepFn *)(obj + 0x17c) = func_021DBB54;
        break;
    case 4:
        *(char **)(obj + 0x194) = d_021E2DF0;
        *(u32 *)(obj + 0x198) = 1;
        *(StepFn *)(obj + 0x17c) = func_021DBBAC;
        break;
    }
}
