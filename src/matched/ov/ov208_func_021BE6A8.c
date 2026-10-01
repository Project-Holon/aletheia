/*
 * function: func_021BE6A8
 * address: 0x021BE6A8
 * packet: pkt_ov208_021BE6A8
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BE70E..021BE710 is two-byte zero alignment padding.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_021BD3F8 0x021BD3F8 thumb ov208
 */
extern unsigned func_020362DC(void);
extern unsigned func_0203633C(void);
extern void func_021BD3F8(void *,int);
void func_021BE6A8(char *p)
{
    unsigned held=func_020362DC();
    unsigned keys=func_0203633C();
    if(!(held&0x3f0)) {
        if(keys&0x40) func_021BD3F8(*(void **)(p+0x30),**(int **)(p+0x94));
        else if(keys&0x80) func_021BD3F8(*(void **)(p+0x30),**(int **)(p+0x8c));
        else if(keys&0x220) func_021BD3F8(*(void **)(p+0x30),**(int **)(p+0x7c));
        else if(keys&0x110) func_021BD3F8(*(void **)(p+0x30),**(int **)(p+0x74));
    }
}
