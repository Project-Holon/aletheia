/*
 * function: func_021FF0A0
 * address: 0x021FF0A0
 * packet: pkt_ov186_021FF0A0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Width: original caller truncates space and sine argument to u16; narrow x local retains the signed halfword update.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B4EC 0x0204B4EC arm
 *   func_0204B49C 0x0204B49C arm
 *   func_0204B5D4 0x0204B5D4 arm
 *   func_0203F684 0x0203F684 arm
 *   func_021FF038 0x021FF038 thumb ov186
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
struct Actor;
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern s16 func_0204B4EC(void *,u16,u32);
extern void func_0204B49C(void *,s16,u16,u32);
extern void func_0204B5D4(struct Actor *actor, u32 value, u32 which);
extern s16 func_0203F684(u16);
extern void func_021FF038(char *,u32);
void func_021FF0A0(char *p)
{
    int direction;
    s16 x;
    float value;
    *(int *)(p+0x28)=(*(int *)(p+0x28)+1)%2;
    if(*(int *)(p+0x28)!=0)return;
    switch(*(int *)(p+0x1C)){
    case 0:
        func_0204B3DC(*(void **)(p+4),1);
        *(int *)(p+0x24)=0;
        *(int *)(p+0x14)=*(s16 *)(p+0x38);
        *(int *)(p+0x1C)=1;
        break;
    case 1:
        if(*(int *)(p+0x24)==3){
            *(int *)(p+0x1C)=2;
            if(func_0204B4EC(*(void **)(p+4),*(u32 *)(p+0x44),0)>0)
                value=0.5f+(float)(func_0204B4EC(*(void **)(p+4),*(u32 *)(p+0x44),0)<<12);
            else
                value=(float)(func_0204B4EC(*(void **)(p+4),*(u32 *)(p+0x44),0)<<12)-0.5f;
            *(int *)(p+0x10)=(int)value;
            *(int *)(p+0x24)=0;
        }else (*(int *)(p+0x24))++;
        break;
    case 2:
        direction=-1;
        if(*(int *)(p+0x48)!=0)direction=1;
        direction=(signed char)direction;
        if(*(int *)(p+0x24)==4){
            *(int *)(p+0x1C)=3;
            *(int *)(p+0x24)=0;
        }else{
            *(int *)(p+0x10)+=-direction*func_0203F684(*(int *)(p+0x20)*65535/360);
            *(int *)(p+0x20)+=32;
            *(int *)(p+0x20)%=360;
            func_0204B49C(*(void **)(p+4),*(int *)(p+0x10)>>12,*(u32 *)(p+0x44),0);
            (*(int *)(p+0x24))++;
        }
        break;
    case 3:
        x=func_0204B4EC(*(void **)(p+4),*(u32 *)(p+0x44),0);
        if(*(int *)(p+0x24)==0){
            *(int *)(p+0x2C)=*(s16 *)(p+0x3C)-x;
            *(int *)(p+0x2C)/=*(s16 *)(p+0x3A);
            (*(int *)(p+0x24))++;
        }else if(*(int *)(p+0x24)==*(s16 *)(p+0x3A)+1){
            x=*(s16 *)(p+0x3C);
            *(int *)(p+0x1C)=4;
        }else{
            x+=(s16)*(int *)(p+0x2C);
            (*(int *)(p+0x24))++;
        }
        func_0204B49C(*(void **)(p+4),x,*(u32 *)(p+0x44),0);
        break;
    case 4:func_021FF038(p,2);break;
    }
    if(*(int *)(p+0x1C)==3){
        if(*(int *)(p+0x14)>410){
            *(int *)(p+0x14)-=410;
            func_0204B5D4(*(void **)(p+4),*(int *)(p+0x14),0);
        }
    }
}
