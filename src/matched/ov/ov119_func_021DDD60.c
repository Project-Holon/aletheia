/*
 * function: func_021DDD60
 * address: 0x021DDD60
 * packet: pkt_ov119_021DDD60
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDBF0 0x021DDBF0 thumb ov119
 *   func_02039CB4 0x02039CB4 arm
 *   func_020399A8 0x020399A8 arm
 *   func_021DD24C 0x021DD24C thumb ov119
 *   func_021DD294 0x021DD294 thumb ov119
 *   func_021DDCF0 0x021DDCF0 thumb ov119
 */

extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int);
extern void func_021DDBF0(char *p);
struct Link;
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
struct Entry;
extern struct Entry *func_020399A8(void);
extern void func_021DD24C(void *);
extern void func_021DD294(void *,int,int);
extern void func_021DDCF0(unsigned char *p);

void func_021DDD60(unsigned char *p)
{
    if(func_021D8A24(p)==0){p[0x11e0]=13;p[0x11e1]=13;func_021D8E84(p,(int)func_021DDBF0);return;} if(func_02039CB4((struct Link *)func_020399A8(),30,8)==0){func_021DD24C(p);return;}func_021DD294(p,0,0);func_021D8E84(p,(int)func_021DDCF0);
}
