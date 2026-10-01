/*
 * function: func_021C6460, func_021C6514, func_021C651C
 * unit: yes
 * address: 0x021C6460
 * packet: pkt_ov128_021C6460
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201283C 0x0201283C thumb
 *   func_02009860 0x02009860 thumb
 *   func_0205994C 0x0205994C arm
 *   func_02009A1C 0x02009A1C thumb
 *   func_021CA014 0x021CA014 thumb ov128
 *   func_02059354 0x02059354 arm
 *   func_0200F43C 0x0200F43C thumb
 *   func_020099C8 0x020099C8 thumb
 *   func_02059980 0x02059980 arm
 *   func_02009A00 0x02009A00 thumb
 *   func_02009918 0x02009918 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
extern void *func_0201283C(void *);
extern void *func_02009860(void *);
extern u64 func_0205994C(void *);
extern int func_02009A1C(void *,int);
extern u64 func_021CA014(void *,int *);
extern int func_02059354(void *,u32,u32);
extern int func_0200F43C(void *,u32,u32,int *);
extern void *func_020099C8(void *,int);
extern void func_02059980(void *,u32,u32);
extern void func_02009A00(void *,int,u32);
extern void func_02009918(void *,int,int,int);
int func_021C6460(char *p,void *q,u32 arg)
{
    int i;
    void *v;
    u64 old,id;
    int valid,result;
    v=func_0201283C(*(void **)(p+4));
    old=func_0205994C(func_02009860(v));
    for(i=0;i<32;i++) {
        if(func_02009A1C(v,i)==0) {
            id=func_021CA014(q,&valid);
            if(valid==1 && id!=old) {
            if(func_02059354(func_02009860(v),(u32)id,(u32)(id>>32))==0) return 1;
            if(func_0200F43C(v,(u32)id,(u32)(id>>32),&result)==0) return 2;
            func_02059980(func_020099C8(v,i),(u32)id,(u32)(id>>32));
            func_02009A00(v,i,arg);
            func_02009918(v,i,9,2);
            return 0;
            }
            return 1;
        }
    }
    return 0;
}
void func_021C6514(char *p,int x) { *(int *)(p+0x60)=x; *(int *)(p+0x64)=1; }
void func_021C651C(char *p,int x) { p[11]=x; }
