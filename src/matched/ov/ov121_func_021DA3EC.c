/*
 * function: func_021DA3EC
 * address: 0x021DA3EC
 * packet: pkt_ov121_021DA3EC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow the return.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045838 0x02045838 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021D9BE8 0x021D9BE8 thumb ov121
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef struct { int x,y; } Pair;
extern void *func_020457B0(int,u16);
extern void func_02043B5C(void *,int);
extern void func_02045838(void *,int);
extern void func_02045CAC(int,int,void *);
extern void func_020307B0(void *);
extern void func_021D9BE8(int,Pair *,void *,void *,int,Pair *);
extern void func_0201C724(void *,void *,s16,s16,void *,int,u16);
void func_021DA3EC(char *p,char *desc,void *dst)
{
    u32 i;
    Pair pos,out;
    void *text=func_020457B0(512,*(u16 *)p);
    for(i=0;i<*(u32 *)(*(char **)(p+4)+4);i++) {
        char *d=desc+i*24;
        if(*(u32 *)d) {
            func_02043B5C(*(void **)(p+i*4+8),(u8)(*(u16 *)(d+20)&31));
            pos.x=*(s16 *)(d+16);
            pos.y=*(s16 *)(d+18);
            func_021D9BE8(*(int *)(d+12),&pos,*(void **)(p+i*4+8),text,*(int *)(*(char **)(p+4)+8),&out);
            if(*(int *)(d+8)) func_02045838(text,*(int *)(d+8));
            else func_02045CAC(*(int *)(*(char **)(p+4)+12),*(int *)(d+4),text);
            func_0201C724(dst,*(void **)(p+i*4+8),(s16)out.x,(s16)out.y,text,*(int *)(*(char **)(p+4)+8),*(u16 *)(d+20));
        }
    }
    func_020307B0(text);
}
