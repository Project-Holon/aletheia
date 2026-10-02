/*
 * function: func_0217CAAC
 * address: 0x0217CAAC
 * packet: pkt_ov019_0217CAAC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217AEFC 0x0217AEFC thumb ov019
 *   func_0217ED04 0x0217ED04 thumb ov019
 *   func_0217ED10 0x0217ED10 thumb ov019
 *   func_0217ECE8 0x0217ECE8 thumb ov019
 *   func_0217ED80 0x0217ED80 thumb ov019
 *   func_0217ED8C 0x0217ED8C thumb ov019
 *   func_0217ED64 0x0217ED64 thumb ov019
 *   func_0217ED98 0x0217ED98 thumb ov019
 *   func_0217ED2C 0x0217ED2C thumb ov019
 *   func_0217ED48 0x0217ED48 thumb ov019
 *   func_0217EDA4 0x0217EDA4 thumb ov019
 *   func_0217EE28 0x0217EE28 thumb ov019
 *   func_0217EDBC 0x0217EDBC thumb ov019
 *   func_0217EDB0 0x0217EDB0 thumb ov019
 *   func_0217EE04 0x0217EE04 thumb ov019
 *   func_0217EDD4 0x0217EDD4 thumb ov019
 *   func_0217EDC8 0x0217EDC8 thumb ov019
 *   func_0217EDE0 0x0217EDE0 thumb ov019
 *   func_0217F060 0x0217F060 thumb ov019
 *   func_0217F210 0x0217F210 thumb ov019
 *   func_0217F1EC 0x0217F1EC thumb ov019
 *   func_0217F794 0x0217F794 thumb ov019
 *   func_0217F7B8 0x0217F7B8 thumb ov019
 *   func_0217F640 0x0217F640 thumb ov019
 *   func_0217F22C 0x0217F22C thumb ov019
 *   func_0217F268 0x0217F268 thumb ov019
 *   func_0217F24C 0x0217F24C thumb ov019
 *   func_0217B8E4 0x0217B8E4 thumb ov019
 *   func_0217BA10 0x0217BA10 thumb ov019
 *   func_0217B974 0x0217B974 thumb ov019
 *   func_0217BAA8 0x0217BAA8 thumb ov019
 *   func_020362DC 0x020362DC arm
 *   func_02012934 0x02012934 thumb
 *   func_0201AAD4 0x0201AAD4 thumb
 *   func_0201AA88 0x0201AA88 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[7]; u8 lo:3; u8 flag:1; } Sub;
typedef struct {
    u8 pad00[0x14]; Sub *f14;
    u8 pad18[0x2d-0x18]; u8 f2d, f2e;
    u8 pad2f[0x58-0x2f]; u16 f58;
    u8 pad5a[0x64-0x5a]; int f64, f68;
} Obj;
typedef struct { u8 count:3; u8 flag:1; } Bits;
u16 func_0217AEFC(u32);
u16 func_0217ED04(int); u16 func_0217ED10(int); u16 func_0217ECE8(int);
u16 func_0217ED80(int); u16 func_0217ED8C(int); u16 func_0217ED64(int);
u16 func_0217ED98(int); u16 func_0217ED2C(int); u16 func_0217ED48(int);
u16 func_0217EDA4(int); u16 func_0217EE28(int); u16 func_0217EDBC(int);
u16 func_0217EDB0(int); u16 func_0217EE04(int); u16 func_0217EDD4(int);
u16 func_0217EDC8(int); u16 func_0217EDE0(int);
u8 func_0217F060(int);
void func_0217F210(u8 *, int, u32); u32 func_0217F1EC(u8 *);
u32 func_0217F794(u8 *, u32); void func_0217F7B8(u8 *);
void func_0217F640(u8 *, int, int, int, int);
void func_0217F22C(u8 *, u32); int func_0217F268(u8 *, u32 *);
void func_0217F24C(u8 *); int func_0217B8E4(u8 *, char);
void func_0217BA10(u8 *, int); int func_0217B974(int);
int func_0217BAA8(u8 *, int, int *, int *);
u32 func_020362DC(void); void *func_02012934(void *);
int func_0201AAD4(void *); int func_0201AA88(void *);
int func_0217CAAC(u8 *ctx, Obj *obj, int a, u8 *state)
{
    int offset, id;
    u32 selected, selected2;
    void *save;
    offset = func_0217AEFC(obj->f58) * 0x8c;
    id = (ctx + offset)[0x291b];
    switch (*state) {
    case 0:
        obj->f2d = id;
        switch (id) {
        case 1: func_0217F210(ctx,a,func_0217ED04(obj->f14->flag)); func_0217B8E4(ctx,0); *state=2; goto done;
        case 2: func_0217F210(ctx,a,func_0217ED10(obj->f14->flag)); func_0217B8E4(ctx,0); *state=2; goto done;
        case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
            func_0217F210(ctx,a,func_0217ECE8(obj->f14->flag)); func_0217B8E4(ctx,0); *state=2; goto done;
        case 20: case 21: case 22: case 23:
            if ((int)((Bits *)((ctx + offset) + 0x2916))->count < func_0217F060(id)) {
                func_0217F210(ctx,a,func_0217ED80(obj->f14->flag));
                func_0217BA10(ctx,id);
                func_0217F640(ctx,a,0,func_0217B974(id),0);
                *state = 3;
                goto done;
            }
            func_0217F210(ctx,a,func_0217ECE8(obj->f14->flag));
            func_0217B8E4(ctx,0); *state=2; goto done;
        case 25:
            if ((int)((Bits *)(ctx + 0x2916 + offset))->count < func_0217F060(id) &&
                ((Bits *)(ctx + 0x2916 + offset))->flag == 0) {
                func_0217F210(ctx,a,func_0217ED8C(obj->f14->flag));
                *state = 10;
                goto done;
            }
            func_0217F210(ctx,a,func_0217ED64(obj->f14->flag)); func_0217B8E4(ctx,0); *state=2; goto done;
        case 3:
            if ((int)((Bits *)((ctx + offset) + 0x2916))->count < func_0217F060(id)) {
                func_0217F210(ctx,a,func_0217ED98(obj->f14->flag));
                *state = 10;
                goto done;
            }
            func_0217F210(ctx,a,func_0217ED2C(obj->f14->flag)); func_0217B8E4(ctx,0); *state=2; goto done;
        case 24: func_0217F210(ctx,a,func_0217ED48(obj->f14->flag)); func_0217B8E4(ctx,0); *state=2; goto done;
        case 0: default: func_0217F210(ctx,a,0x151); func_0217B8E4(ctx,0); *state=2; goto done;
        }
        break;
    case 2:
        if (func_0217F1EC(ctx) == 1 && (func_020362DC() & 0xf3)) return 1;
        break;
    case 1:
        if (func_0217F1EC(ctx) == 1) return 1;
        break;
    case 3:
        if (func_0217F794(ctx,a) == 1) *state = 4;
        break;
    case 4:
        if (func_0217F1EC(ctx) == 1) {
            func_0217F7B8(ctx); func_0217F22C(ctx,a); (*state)++;
        }
        break;
    case 5:
        if (func_0217F268(ctx,&selected) == 1) {
            func_0217F24C(ctx);
            if (selected == 0) {
                func_0217F210(ctx,a,func_0217EDA4(obj->f14->flag));
                func_0217B8E4(ctx,0); *state = 2;
            } else if (func_0217BAA8(ctx,obj->f2d,&obj->f64,&obj->f68) == 0) {
                func_0217F210(ctx,a,0x13e); func_0217B8E4(ctx,0); *state = 6;
            } else {
                obj->f2e = selected; func_0217B8E4(ctx,0x26);
                func_0217F210(ctx,a,func_0217EE28(obj->f14->flag)); *state = 1;
            }
        }
        break;
    case 6:
        if (func_0217F1EC(ctx) == 1) return 1;
        func_0217F640(ctx,a,obj->f64,func_0217B974(obj->f2d),1); (*state)++;
        break;
    case 7:
        if (func_0217F794(ctx,a) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(ctx);
            if (obj->f68 == -1) *state = 1; else (*state)++;
        }
        break;
    case 8:
        func_0217F640(ctx,a,obj->f64,func_0217B974(obj->f2d),2); (*state)++;
        break;
    case 9:
        if (func_0217F794(ctx,a) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(ctx); *state = 1;
        }
        break;
    case 10:
        if (func_0217F1EC(ctx) == 1) {
            func_0217F22C(ctx,a); (*state)++;
        }
        break;
    case 11:
        if (func_0217F268(ctx,&selected2) == 1) {
            func_0217F24C(ctx);
            if (selected2 == 0) {
                switch (obj->f2d) {
                case 3: func_0217F210(ctx,a,func_0217EDBC(obj->f14->flag)); break;
                case 25: func_0217F210(ctx,a,func_0217EDB0(obj->f14->flag)); break;
                }
                func_0217B8E4(ctx,0); *state = 2;
            } else {
                obj->f2e = selected2; func_0217B8E4(ctx,0x26); *state = 1;
                switch (obj->f2d) {
                case 3: func_0217F210(ctx,a,func_0217EE04(obj->f14->flag)); break;
                case 25:
                    save = func_02012934((void *)(*(u32 **)ctx)[2]);
                    if (func_0201AAD4(save) > 0) {
                        func_0217F210(ctx,a,func_0217EDD4(obj->f14->flag));
                        func_0217B8E4(ctx,0); *state = 2;
                    } else if (func_0201AA88(save) == 0) {
                        func_0217F210(ctx,a,func_0217EDC8(obj->f14->flag));
                        func_0217B8E4(ctx,0); *state = 2;
                    } else func_0217F210(ctx,a,func_0217EDE0(obj->f14->flag));
                    break;
                }
            }
        }
        break;
    }
done:
    return 0;
}
