/*
 * file:     ghttpEncryption_p05.c
 * unit:     yes
 * function: func_021C1C80, func_021C1C88, func_021C1C90, func_021C1C98
 * address:  0x021C1C80
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
 *   d_021CE7B0    0x021CE7B0  data  a4
 *   d_021CE713    0x021CE713  data  a1
 *   d_021CED3C    0x021CED3C  data  a4
 *   func_0217EAE0 0x0217EAE0  arm
 *   func_0217D254 0x0217D254  arm
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_0217EAE0(void *);
extern void func_0217D254(int, int, int, void *, ...);
int func_021C1C80(void *connection, void *encryptor, char *buffer, int *bufferLen);
int func_021C1C88(void);
int func_021C1C90(void);
int func_021C1C98(int unused, unsigned int *p);
extern char d_021CE7B0[];
extern char d_021CE713[];
extern char d_021CED3C[];

/*
 * Constant predicate: always 1.
 */
int func_021C1C80(void *connection, void *encryptor, char *buffer, int *bufferLen)
{
    return 1;
}

int func_021C1C88(void)
{
    return 3;
}

/*
 * sdk:      ghiEncryptorSslDecryptFunc (libdwcgsghttp.TWL.HYB.a(ghttpencryption.o))
 *
 * notes:    `mov r0, #3; bx lr`; ghttpSetRequestEncryptionEngine's relocation at
 *           +0xE4 (ABS32 ghiEncryptorSslDecryptFunc) is the pool word at
 *           0x021C1180.  Byte-identical to 0x021C1C88: the name comes from that
 *           relocation.  Seeded in layout/function_starts.txt.
 */
int func_021C1C90(void)
{
    return 3;
}


int func_021C1C98(int unused, unsigned int *p)
{
    func_0217D254(8, 4, 0xf, d_021CED3C, d_021CE7B0, d_021CE713, 0x4d5);
    if (p != 0) {
        unsigned int *q = (unsigned int *)p[0];
        if (q != 0) {
            if (q[0] != 0)
                func_0217EAE0((void *)q[0]);
            func_0217EAE0(q);
            p[0] = 0;
        }
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
    }
    return 1;
}
