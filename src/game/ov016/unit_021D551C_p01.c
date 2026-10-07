/*
 * file:     unit_021D551C_p01.c
 * unit:     yes
 * function: func_021D551C, func_021D556C, func_021D5580
 * address:  0x021D551C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MemEffect                        0x021DE67C  data
 */
typedef unsigned int   u32;

typedef _Bool bool;

struct EFFPRM {
    char pad[9];
    bool f9;
    char pad2[2];
};

struct MEMEFFECT {
    struct EFFPRM param[2];
};

extern void *func_021D6414(unsigned long size, int alignment);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_021D6438(void **mem);
void func_021D551C(void);
void func_021D556C(void);
bool DWCi_EFFlCheck(int lcd);
extern struct MEMEFFECT *MemEffect;


/*
 * Allocate a 0x18-byte block, publish it, and clear two 0x1000-wide register spans.
 * Addresses are Black-image addresses.
 */
void func_021D551C(void)
{
    unsigned short *p;

    *(int *)0x021DE67C = (int)func_021D6414(0x18, 4);
    p = (unsigned short *)0x04000050;
    func_0207D658((u32)p, 0x3f, 0x10);
    func_0207D658((u32)(p + 0x800), 0x3f, 0x10);
}


/*
 * Tail-call func_021D6438 with the address of 0x021DE67C.
 * Addresses are Black-image addresses.
 */
void func_021D556C(void)
{
    func_021D6438((void *)0x021DE67C);
}


bool DWCi_EFFlCheck(int lcd)
{
    struct EFFPRM *p;

    if (lcd == 1)
        p = &MemEffect->param[0];
    else
        p = &MemEffect->param[1];
    return p->f9;
}
