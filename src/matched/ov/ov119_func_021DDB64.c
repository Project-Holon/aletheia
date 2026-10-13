/*
 * function: func_021DDB64
 * address: 0x021DDB64
 * packet: pkt_ov119_021DDB64
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021DD080 0x021DD080 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDB10 0x021DDB10 thumb ov119
 */

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int func_021E12AC(char *p);
extern void func_021DD080(void *a, void *b, void *c);
extern void func_021D8E84(void *,int);
extern void func_021DDB10(unsigned char *p);

void func_021DDB64(unsigned char *p)
{
    GFL_NET_HANDLE_GetCurrentHandle();
    if(func_021E12AC((char *)p)) {
        func_021DD080((void *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()),(void *)25,p);
        func_021D8E84(p,(int)func_021DDB10);
    }
}
