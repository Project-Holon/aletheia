/*
 * file:     br_proc_sys_p02.c
 * unit:     yes
 * function: func_021F9390, func_021F93D4
 * address:  0x021F9390
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_02034714 0x02034714 arm
 *   d_02200D00 0x02200D00 data
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

extern u32 func_021FC4DC(u8 *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
void func_021F9390(int *out,int *source,int unused,int type);
void func_021F93D0(void);
void func_021F93D4(int *out,int *source,int *ctx,int type);
extern const char d_02200D00[];

/*
 * Extent includes empty follower021F93D0; zeros021F93CE and021F93D2 are alignment.
 */
void func_021F9390(int *out,int *source,int unused,int type)
{
    out[3]=source[1];
    out[2]=source[3];
    out[4]=source[2];
    out[1]=func_021FC4DC((u8 *)source[0]);
    out[5]=source[4];
    if(type==1) out[0]=1;
    else if(((int *)source[6])[1]==0) out[0]=0;
    else out[0]=2;
}

void func_021F93D0(void)
{
}

/*
 * note: 2026-10-05 wave P15 D3. Real extent 252 bytes (pool ends 0x021F94CC); the unlabelled
 *   follower at 0x021F94D0 is a separate function. Written from the listing, EXACT* at the first compile.
 */
void func_021F93D4(int *out,int *source,int *ctx,int type)
{
    out[3]=2;
    out[10]=*(int *)((char *)source[6]+0xc)+0xc;
    out[9]=*(int *)((char *)source[6]+8)+0x17A0;
    if(*(int *)((char *)source[6]+4)==1) {
        switch(**(int **)((char *)source[6]+0xc)) {
        case 0: out[0]=1; break;
        case 1: out[0]=7; break;
        case 2: out[0]=10; break;
        }
    } else {
        switch(type) {
        case 2:
            switch(ctx[2]) {
            case 0: out[0]=1; break;
            case 1: case 2: case 3: out[0]=2; break;
            case 4: func_02034714(d_02200D00,0,d_02200D00); out[0]=7; break;
            case 5: func_02034714(d_02200D00,0,d_02200D00); out[0]=7; break;
            }
            break;
        case 5: out[0]=7; break;
        case 6: case 7: out[0]=6; break;
        case 12:
            if(ctx[7]==0) out[3]=4;
            out[0]=10;
            break;
        default:
            switch(**(int **)((char *)source[6]+0xc)) {
            case 0: out[0]=0; break;
            case 1: out[0]=5; break;
            case 2: out[0]=10; break;
            }
            break;
        }
    }
    out[6]=source[1];
    out[4]=source[3];
    out[7]=source[2];
    out[5]=func_021FC4DC((u8 *)source[0]);
    out[8]=*(int *)((char *)source[6]+8)+0x1748;
}
