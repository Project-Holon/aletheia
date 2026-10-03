/*
 * function: func_021FF248
 * address: 0x021FF248
 * packet: pkt_ov186_021FF248
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: int direction with explicit signed-char cast at use retains the original lsls/asrs byte truncation; a signed-char local folds it away and compiles 232/236 bytes.
 * Width: original caller truncates space and sine arguments to u16; full callee signatures otherwise copied.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B49C 0x0204B49C arm
 *   func_0204B5D4 0x0204B5D4 arm
 *   func_0203F684 0x0203F684 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
extern void func_0204B3DC(void *,u32);
extern void func_0204B49C(void *,s16,u16,u32);
extern void func_0204B5D4(void *,u32,u32);
extern s16 func_0203F684(u16);
void func_021FF248(char *p)
{
    int direction;
    int position;
    float value;
    *(int *)(p+0x28)=(*(int *)(p+0x28)+1)%2;
    if(*(int *)(p+0x28)!=0)return;
    switch(*(int *)(p+0x1C)){
    case 0:
        func_0204B3DC(*(void **)(p+4),1);
        func_0204B49C(*(void **)(p+4),*(s16 *)(p+0x3C),*(u32 *)(p+0x44),0);
        if(*(s16 *)(p+0x3C)>0)value=0.5f+(float)(*(s16 *)(p+0x3C)<<12);
        else value=(float)(*(s16 *)(p+0x3C)<<12)-0.5f;
        *(int *)(p+0x10)=(int)value;
        *(int *)(p+0x20)=*(s16 *)(p+0x40);
        *(int *)(p+0x1C)=1;
        break;
    case 1:
        direction=-1;
        if(*(int *)(p+0x48)!=0)direction=1;
        position=*(int *)(p+0x10)+-(signed char)direction*(func_0203F684(*(int *)(p+0x20)*65535/360)*3);
        *(int *)(p+0x20)+=*(s16 *)(p+0x42);
        *(int *)(p+0x20)%=360;
        func_0204B49C(*(void **)(p+4),position>>12,*(u32 *)(p+0x44),0);
        break;
    }
    if(*(int *)(p+0x14)>410){
        *(int *)(p+0x14)-=410;
        func_0204B5D4(*(void **)(p+4),*(int *)(p+0x14),0);
    }
}
