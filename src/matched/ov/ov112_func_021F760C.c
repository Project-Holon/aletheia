/*
 * function: func_021F760C
 * address: 0x021F760C
 * packet: pkt_ov112_021F760C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: 4B3C forwards full r0 to4AA8(int); its extern remains int despite superseded i5 narrow score.
 * lever: split records/record pointer steps, expand immutable position at4B88, record/id declaration swap (permuter183).
 * symbols:
 *   func_021F5204 0x021F5204 thumb ov112
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_021F77EC 0x021F77EC thumb ov112
 *   func_021F4B3C 0x021F4B3C thumb ov112
 *   func_021F4B88 0x021F4B88 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_0204F428 0x0204F428 arm
 *   func_0204F720 0x0204F720 arm
 *   func_020056EC 0x020056EC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern u8 *func_021F5204(void *,u8 *,u32);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
struct Personal;
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *);
extern void func_021F77EC(u32,u8 *,u32);
extern int func_021F4B3C(int);
extern void *func_021F4B88(void *,int,u32,int *);
extern void func_021F4EB4(u32 unused, u32 p, s16 a, s16 b);
extern void func_021F4E6C(int,int,int);
extern int func_0204F428(void *,u32,u16,u16,int *,u8,u32,u32);
extern void func_0204F720(void *,u32,u32 *);
extern u32 func_020056EC(u32);
void func_021F760C(u8 *p,u8 *input)
{
    u8 i;
    void *personal;
    int *position;
    u8 *records;
    u8 *q;
    u8 *row;
    u32 id;
    int scale;
    u8 *record;
    u32 flag;
    for(i=0;i<9;i++) {
        if(*(int *)(p+20+264*i)==0) break;
    }
    q=p+20+264*i;
    *(int *)q=1;
    *(int *)(q+4)=1;
    *(int *)(q+8)=1;
    *(int *)(q+12)=0;
    *(int *)(q+16)=0;
    *(int *)(q+20)=0;
    *(int *)(q+260)=0;
    *(u8 **)(q+88)=func_021F5204(*(void **)(p+12),input,1);
    personal=func_0201ADE4((u32)*(u16 *)(input+8),(u32)input[11],(u32)*(u16 *)p);
    if(func_0201AE1C(personal,16)==1) *(int *)(q+16)=1;
    if(func_0201AE1C(personal,34)==1) *(int *)(q+20)=1;
    func_0201AE14(personal);
    *(int *)(q+24)=0;
    *(int *)(q+28)=0;
    *(int *)(q+32)=0;
    *(int *)(q+48)=0;
    *(int *)(q+52)=0;
    *(int *)(q+56)=0;
    *(int *)(q+36)=4096;
    *(int *)(q+40)=4096;
    *(int *)(q+44)=4096;
    func_021F77EC((u32)p,q,*(u16 *)(input+8));
    *(u16 *)(q+72)=0;
    position=(int *)(q+24);
    scale=1024;
    records=input;
    records=records+20;
    for(i=0;i<9;i++) {
        id=*(u16 *)(input+20+6*i);
        record=records;
        record=record+6*i;
        row=q+4*i;
        *(u8 **)(row+168)=record;
        if(id!=255) {
            *(int *)(row+204)=1;
            *(int *)(row+96)=func_021F4B3C(id);
            *(void **)(row+132)=func_021F4B88(*(void **)(p+16),id,*(u32 *)(row+96),(int *)(q+24));
            func_021F4EB4(*(int *)(p+16),*(int *)(row+132),scale,scale);
            func_021F4E6C(*(int *)(p+16),*(int *)(row+132),0);
        } else {
            *(int *)(row+204)=0;
            *(int *)(row+96)=0;
            *(int *)(row+132)=0;
        }
    }
    *(int *)(q+92)=func_0204F428(*(void **)(p+8),*(u32 *)(p+1080),1024,768,(int *)(q+24),30,0,0);
    flag=1;
    func_0204F720(*(void **)(p+8),*(u32 *)(q+92),&flag);
    *(u16 *)(q+80)=func_020056EC(150)>>1;
    *(int *)(q+76)=1;
}
