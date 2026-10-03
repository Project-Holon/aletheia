/*
 * function: func_021C9448
 * address: 0x021C9448
 * packet: pkt_ov093_021C9448
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: compiled 50 bytes; 021C947A..021C947C is alignment padding.
 * note: caller consumes live r0 after void-declared func_021D5EFC;
 *       return interface follows its explicit u8 truncation at 021C9470.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D5EFC 0x021D5EFC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
extern int func_021D5B68(void *);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021D5EFC(char *);
int func_021C9448(u8 *p, u8 *e)
{
    char *a;
    a = (char *)func_021B9934(*(char **)(p + 8), e[4]);
    if (func_021D5B68(a) == 0) {
        func_021CD4B0(*(void **)(p + 12), 12, e[4]);
        return (u8)func_021D5EFC(a);
    }
    return 0;
}
