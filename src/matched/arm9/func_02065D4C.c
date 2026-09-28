/*
 * unit:     no
 * function: func_02065D4C
 * address:  0x02065D4C
 * packet:   pkt_02065D4C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02147B88  0x02147B88  data  a4
 *   func_02066E20  0x02066E20  arm
 *   func_02066DEC  0x02066DEC  arm
 *   func_02066E10  0x02066E10  arm
 *   func_02066DFC  0x02066DFC  arm
 *   func_02065878  0x02065878  arm
 */

typedef struct
{
    unsigned char pad[0x80];
    int f80;
} Inner;

typedef struct
{
    unsigned char pad[8];
    Inner *f8;
} Ctx;

extern Ctx g_02147B88;

extern int func_02066E20(void);
extern void func_02066DEC(int);
extern void func_02066E10(int);
extern void func_02066DFC(void);
extern void func_02065878(void *);

void func_02065D4C(void *a0)
{
    int saved;

    if (((volatile Ctx *)&g_02147B88)->f8->f80 != 0)
    {
        saved = func_02066E20();
        func_02066DEC(1);
        func_02066E10(((volatile Ctx *)&g_02147B88)->f8->f80);
        func_02065878(a0);
        func_02066DEC(0);
        func_02066E10(saved);
        func_02066DFC();
    }
    else
    {
        func_02065878(a0);
    }
}
