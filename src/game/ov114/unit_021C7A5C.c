/*
 * file:     unit_021C7A5C.c
 * unit:     yes
 * function: func_021C7A5C, func_021C7A68
 * address:  0x021C7A5C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA448  0x021BA448  arm  ov114
 *   func_021BA4E4  0x021BA4E4  arm  ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_021BA448(void);
extern int func_021BA4E4(char *p_p, unsigned long n);
void func_021C7A5C(void);
void func_021C7A68(char *p, u32 n);


/*
 * ov114 tail-call thunk via `ldr ip,pool; bx ip`.
 */
void func_021C7A5C(void)
{
    func_021BA448();
}


void func_021C7A68(char *p, u32 n)
{
    func_021BA4E4(p, n);
}
