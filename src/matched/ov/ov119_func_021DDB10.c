/*
 * function: func_021DDB10
 * address: 0x021DDB10
 * packet: pkt_ov119_021DDB10
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_02039CB4 0x02039CB4 arm
 *   func_021DD24C 0x021DD24C thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021DD294 0x021DD294 thumb ov119
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DEA24 0x021DEA24 thumb ov119
 */

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int func_021D8A24(void *);
struct Link;
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern int func_021DD24C(char *p);
extern void func_021E1098(char *p);
extern void func_021DD294(char *p, int a, int b);
extern int func_021D8980(char *p);
extern void func_021DD09C(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DEA24(char *p);

void func_021DDB10(unsigned char *p)
{
    GFL_NET_HANDLE_GetCurrentHandle(); if(func_021D8A24(p)) { if(func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),25,8)==0) {func_021DD24C((char *)p);return;} } func_021E1098((char *)p);func_021DD294((char *)p,0,0);func_021D8980((char *)p);func_021DD09C((char *)p);func_021D8E84(p,(int)func_021DEA24);
}
