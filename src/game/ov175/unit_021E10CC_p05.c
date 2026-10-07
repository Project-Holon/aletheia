/*
 * file:     unit_021E10CC_p05.c
 * unit:     yes
 * function: func_021E17D8, func_021E1830
 * address:  0x021E17D8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02084F80  0x02084F80  arm
 *   func_02084FA8  0x02084FA8  arm
 *   g_021E4640     0x021E4640  data
 *   DWCi_IsError      0x02059F38  arm
 *   DWC_GetLastError  0x02059E18  arm
 *   g_021E464C        0x021E464C  data
 *   g_021E5334        0x021E5334  data
 *   g_021E4594        0x021E4594  data
 *   g_021E45A8        0x021E45A8  data
 *   g_021E4660        0x021E4660  data
 */
typedef struct {
    int unk0;
    void *sake;
    int state;
} Tbl;

extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern int func_02084FA8(char *s, unsigned int n, const char *format, void *arg);
extern int DWCi_IsError(void);
extern int DWC_GetLastError(int *errorCode);
void func_021E17D8(int line, char *fmt, ...);
int func_021E1830(int *result);
extern char g_021E4640[];
extern char g_021E464C[];
extern Tbl g_021E5334;
extern char g_021E4594[];
extern char g_021E45A8[];
extern char g_021E4660[];


/*
 * sdk:      DWCi_GdbPrintf (dwc_gdb.o)
 */
void func_021E17D8(int line, char *fmt, ...)
{
    char str_buf[256];
    int str_len;
    char *args;

    str_len = func_02084F80(str_buf, 256, g_021E4640, line);
    args = (char *)((((unsigned int)&fmt) & ~3) + 4);
    func_02084FA8(str_buf + str_len, 256 - str_len, fmt, args);
}


int func_021E1830(int *result)
{
    if (DWCi_IsError()) {
        func_021E17D8(0x568, g_021E464C, DWC_GetLastError(0));
        if (result != 0) {
            *result = 0x16;
        }
        return 1;
    }
    switch (g_021E5334.state) {
    case 0:
        func_021E17D8(0x570, g_021E4594);
        if (result != 0) {
            *result = 0x13;
        }
        return 1;
    case 2:
        func_021E17D8(0x575, g_021E45A8);
        if (result != 0) {
            *result = 0x14;
        }
        return 1;
    case 3:
        func_021E17D8(0x57a, g_021E4660);
        if (result != 0) {
            *result = 0x17;
        }
        return 1;
    }
    return 0;
}
