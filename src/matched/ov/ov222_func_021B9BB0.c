/*
 * function: func_021B9BB0, func_021B9BFC
 * unit: yes
 * address: 0x021B9BB0
 * packet: pkt_ov222_021B9BB0
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * function_starts: 021B9BFC
  * extent: lead 74B; 2 padding bytes; approved follower 30B; 2 terminal zero bytes at 021B9C1A outside TU.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201C6C4 0x0201C6C4 thumb
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Cfg;
struct Descriptor;
struct PrintSys;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
void func_021B9BB0(char*p)
{
    u8 i;
    for(i=0;i<5;i++){
        char*q=p+i*4;
        if(*(int*)(q+0x30)==0){
            if(func_0201C6C4(*(void**)(p+0x10),func_02045770(*(void**)(q+0x1c)))==0){
                void*h=*(void**)(q+0x1c);
                func_02045334(h);func_02045374(h);func_02041B6C(func_02045730(h));
                *(int*)(q+0x30)=1;
            }
        }
    }
}
int func_021B9BFC(char*p)
{
    u8 i;
    for(i=0;i<5;i++){
        if(*(int*)(p+i*4+0x30)==0)return 0;
    }
    return 1;
}
