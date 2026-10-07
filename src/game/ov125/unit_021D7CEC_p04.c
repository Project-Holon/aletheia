/*
 * file:     unit_021D7CEC_p04.c
 * unit:     yes
 * function: func_021D8438, func_021D8444, func_021D8588
 * address:  0x021D8438
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02085A38  0x02085A38  arm
 *   func_02167FA8 0x02167FA8 arm ov009
 *   func_02168040 0x02168040 arm ov009
 *   func_02059E38 0x02059E38 arm
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021D8D30 0x021D8D30 data a4
 */
#define D(o) (*(int *)(d_021D9E40 + (o)))
typedef unsigned long u32_021D8438;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021D8444;

typedef struct { u8 b[301]; } Sav;

typedef struct { int w[0x138 / 4]; } Blob;

extern void func_02085A38(u32_021D8438 msec);
extern int func_02167FA8(char *svl, void *result);
extern int func_02168040(void);
extern int func_02059E38(int *, int *);
extern void func_021D7CAC(void);
extern void func_021D7CC0(void);
void func_021D8438(int msec);
int func_021D8444(void);
void func_021D8588(void);
extern char d_021D9E40[];
extern const char d_021D8D30[];


/*
 * ARM tail call: ldr ip, =target; bx ip (the form mwcc emits, as in ov009 func_0216F008.c).
 */
void func_021D8438(int msec)
{
    func_02085A38(msec);
}


#pragma opt_propagation off

int func_021D8444(void)
{
    u8 buf[0x174];
    int b, a;
    int r;

    if (D(0x138) == 1)
        return 1;
    if (func_02167FA8((char *)d_021D8D30, buf) == 0) {
        D(0x250) = 0xE;
        return 0;
    }
    for (;;) {
        r = func_02168040();
        if (r == 3) {
            Sav *t = (Sav *)(d_021D9E40 + 6);
            *t = *(Sav *)(buf + 0x45);
            *(Blob *)(*(char **)&D(0x258) + 8) = *(Blob *)d_021D9E40;
            D(0x138) = 1;
            return 1;
        }
        if (r == 4) {
            func_02059E38(&a, &b);
            D(0x250) = 0xE;
            return 0;
        }
        if (r == 5) {
            D(0x250) = 0xE;
            return 0;
        }
        func_021D7CAC();
        if (D(0x268) == 1) {
            D(0x250) = 0xD;
            func_021D7CC0();
            return 0;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
}

#pragma opt_propagation reset

void func_021D8588(void){}
