/*
 * function: ov208_func_021BF9B0
 * address:  0x021BF9B0
 * packet:   pkt_ov208_021BF9B0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov208_func_021BC3B4  0x021BC3B4  thumb  ov208
 *   ov208_func_021BC3B8  0x021BC3B8  thumb  ov208
 *   func_0207D4B0  0x0207D4B0  arm
 *   data_021C85C0  0x021C85C0  data
 *   data_021C8618  0x021C8618  data
 *   func_020403F4  0x020403F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040618  0x02040618  arm
 *   func_0204047C  0x0204047C  arm
 *   ov208_func_021C0090  0x021C0090  thumb  ov208
 *   ov208_func_021C0134  0x021C0134  thumb  ov208
 *   ov208_func_021C0450  0x021C0450  thumb  ov208
 *   ov208_func_021C0544  0x021C0544  thumb  ov208
 *   ov208_func_021BC844  0x021BC844  thumb  ov208
 *   ov208_func_021C0788  0x021C0788  thumb  ov208
 *   ov208_func_021C08E8  0x021C08E8  thumb  ov208
 *   ov208_func_021C0B10  0x021C0B10  thumb  ov208
 *   ov208_func_021C1AD4  0x021C1AD4  thumb  ov208
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   ov208_func_021C0C50  0x021C0C50  thumb  ov208
 *   ov208_func_021C0C8C  0x021C0C8C  thumb  ov208
 *   ov208_func_021BC758  0x021BC758  thumb  ov208
 *   ov208_func_021BC718  0x021BC718  thumb  ov208
 *   ov208_func_021BC4F4  0x021BC4F4  thumb  ov208
 *   ov208_func_021C24F0  0x021C24F0  thumb  ov208
 *   ov208_func_021BC4D8  0x021BC4D8  thumb  ov208
 *   ov208_func_021BC6D8  0x021BC6D8  thumb  ov208
 *   ov208_func_021BDAD0  0x021BDAD0  thumb  ov208
 *   ov208_func_021BC3BC  0x021BC3BC  thumb  ov208
 *   ov208_func_021BDAAC  0x021BDAAC  thumb  ov208
 *   ov208_func_021BDAD4  0x021BDAD4  thumb  ov208
 *   ov208_func_021BDBB8  0x021BDBB8  thumb  ov208
 *   ov208_func_021BDC48  0x021BDC48  thumb  ov208
 *   ov208_func_021BC3A4  0x021BC3A4  thumb  ov208
 *   GAME_DATA_CheckSaveFlag  0x02012BF8  thumb
 *   ov208_func_021BDC14  0x021BDC14  thumb  ov208
 *   ov208_func_021BE840  0x021BE840  thumb  ov208
 *   ov208_func_021BE82C  0x021BE82C  thumb  ov208
 *   ov208_func_021BE844  0x021BE844  thumb  ov208
 *   ov208_func_021BC4C8  0x021BC4C8  thumb  ov208
 *   ov208_func_021BC6C8  0x021BC6C8  thumb  ov208
 *   ov208_func_021BDBA0  0x021BDBA0  thumb  ov208
 *   ov208_func_021C2458  0x021C2458  thumb  ov208
 *   ov208_func_021C1D0C  0x021C1D0C  thumb  ov208
 *   ov208_func_021C1D24  0x021C1D24  thumb  ov208
 *   ov208_func_021C23BC  0x021C23BC  thumb  ov208
 *   ov208_func_021C10B8  0x021C10B8  thumb  ov208
 *   ov208_func_021C24A4  0x021C24A4  thumb  ov208
 *   ov208_func_021BC4E4  0x021BC4E4  thumb  ov208
 *   ov208_func_021BC6F8  0x021BC6F8  thumb  ov208
 *   ov208_func_021BE854  0x021BE854  thumb  ov208
 *   ov208_func_021BDAE8  0x021BDAE8  thumb  ov208
 *   ov208_func_021C252C  0x021C252C  thumb  ov208
 *   ov208_func_021BC508  0x021BC508  thumb  ov208
 *   ov208_func_021C0130  0x021C0130  thumb  ov208
 *   ov208_func_021BC99C  0x021BC99C  thumb  ov208
 *   ov208_func_021C0968  0x021C0968  thumb  ov208
 *   ov208_func_021C0A8C  0x021C0A8C  thumb  ov208
 *   ov208_func_021C1810  0x021C1810  thumb  ov208
 *   ov208_func_021BC46C  0x021BC46C  thumb  ov208
 *   ov208_func_021BC678  0x021BC678  thumb  ov208
 *   ov208_func_021C0714  0x021C0714  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct BgTemplate {
    u32 w[8];
};

struct BgEntry {
    u32 bg;
    struct BgTemplate tmpl;
    u32 type;
    u32 on;
};

extern const struct BgEntry data_021C85C0[2];
extern const struct BgEntry data_021C8618[2];

extern void *ov208_func_021BC3B4(int key);
extern void *ov208_func_021BC3B8(int key);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_020403F4(u32 i);
extern void func_0203FCA0(u8 bgId, const struct BgTemplate *tmpl, u8 type);
extern void func_020414AC(u8 bgId);
extern void func_02040588(u8 which, u8 enable);
extern void func_02040618(u32 bgId, u32 which, u32 value);
extern void func_0204047C(int idx, unsigned short val);
extern void ov208_func_021C0090(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0134(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0450(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0544(u16 *heap, u8 *p, int key);
extern u32  ov208_func_021BC844(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal);
extern void ov208_func_021C0788(u16 *heap, u8 *p, int key);
extern void ov208_func_021C08E8(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0B10(u16 *heap, u8 *p, int key);
extern void ov208_func_021C1AD4(u16 *heap, u8 *p, int key);
struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void ov208_func_021C0C50(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0C8C(u16 *heap, u8 *p, int key, int on);
extern void ov208_func_021BC758(u32 fade);
extern void ov208_func_021BC718(u32 fade);
extern void ov208_func_021BC4F4(int sub, u32 blend);
extern void ov208_func_021C24F0(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC4D8(u32 blend);
extern void ov208_func_021BC6D8(u32 fade);
extern int  ov208_func_021BDAD0(void *s);
extern u16  ov208_func_021BC3BC(char *p);
extern void ov208_func_021BDAAC(void *s, u32 mode, u32 kind, u32 flag);
extern void ov208_func_021BDAD4(void *s, int v);
extern void ov208_func_021BDBB8(void *s, u32 kind);
extern void ov208_func_021BDC48(void *s, u32 on);
extern int  ov208_func_021BC3A4(int key);
extern int GAME_DATA_CheckSaveFlag(int a0, int a1);
extern void ov208_func_021BDC14(void *s, int b);
extern int  ov208_func_021BE840(void *icon);
extern void ov208_func_021BE82C(void *icon, int kind);
extern void ov208_func_021BE844(void *icon);
extern int  ov208_func_021BC4C8(u32 blend);
extern int  ov208_func_021BC6C8(u32 fade);
extern void ov208_func_021BDBA0(void *s);
extern void ov208_func_021C2458(u16 *heap, u8 *p, int key);
extern void ov208_func_021C1D0C(u16 *heap, u8 *p, int key);
extern void ov208_func_021C1D24(u16 *heap, u8 *p, int key);
extern void ov208_func_021C23BC(u8 *p);
extern void ov208_func_021C10B8(u16 *heap, u8 *p, int key);
extern void ov208_func_021C24A4(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC4E4(u32 blend);
extern void ov208_func_021BC6F8(u32 fade);
extern void ov208_func_021BE854(void *icon);
extern void ov208_func_021BDAE8(void *s, int v);
extern void ov208_func_021C252C(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC508(int sub, u32 blend);
extern void ov208_func_021C0130(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC99C(u32 win);
extern void ov208_func_021C0968(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0A8C(u16 *heap, u8 *p, int key);
extern void ov208_func_021C1810(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC46C(u32 main, u32 sub);
extern void ov208_func_021BC678(u32 fade);
extern void ov208_func_021C0714(u16 *heap, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))

int ov208_func_021BF9B0(void *proc, int *seq, u16 *heap, u8 *p, int key)
{
    void *scene;
    void *icon;
    u32 j;
    u32 k;
    u8 i;
    int ready;

    scene = ov208_func_021BC3B4(key);
    icon = ov208_func_021BC3B8(key);
    switch (*seq) {
    case 0:
        *seq = 1;
        func_0207D4B0(1, 5, 0);
        for (j = 0; j < 2; j++) {
            func_020403F4((u8)data_021C85C0[j].bg);
            func_0203FCA0(data_021C85C0[j].bg, &data_021C85C0[j].tmpl, data_021C85C0[j].type);
            func_020414AC(data_021C85C0[j].bg);
            func_02040588(data_021C85C0[j].bg, data_021C85C0[j].on);
        }
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                func_02040618(i, 0, 0);
                func_02040618(i, 3, 0);
                func_020414AC(i);
            }
        }
        func_0204047C(2, 2);
        func_0204047C(3, 3);
        func_0204047C(0, 1);
        func_0204047C(6, 1);
        func_0204047C(7, 2);
        func_0204047C(4, 3);
        ov208_func_021C0090(heap, p, key);
        ov208_func_021C0134(heap, p, key);
        ov208_func_021C0450(heap, p, key);
        ov208_func_021C0544(heap, p, key);
        W(8) = ov208_func_021BC844(*heap, 1, 4, 9, 10);
        ov208_func_021C0788(heap, p, key);
        ov208_func_021C08E8(heap, p, key);
        ov208_func_021C0B10(heap, p, key);
        ov208_func_021C1AD4(heap, p, key);
        CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + W(0x64) * 4 + 0x5c)), 1);
        ov208_func_021C0C50(heap, p, key);
        if (W(0x90) == 1)
            ov208_func_021C0C8C(heap, p, key, 1);
        ov208_func_021BC758(W(0x420));
        ov208_func_021BC718(W(0x420));
        break;
    case 1:
        *seq = 2;
        ov208_func_021BC4F4(1, W(0x41c));
        ov208_func_021C24F0(heap, p, key);
        break;
    case 2:
        *seq = 3;
        ov208_func_021BC4D8(W(0x418));
        ov208_func_021BC6D8(W(0x420));
        if (ov208_func_021BDAD0(scene) != 2) {
            ov208_func_021BDAAC(scene, 0, 1, ov208_func_021BC3BC((char *)key) > 1);
            ov208_func_021BDAD4(scene, 0);
        } else {
            ov208_func_021BDBB8(scene, 1);
        }
        ov208_func_021BDC48(scene, 0);
        W(0x88) = 0;
        ov208_func_021BDC14(scene, GAME_DATA_CheckSaveFlag(ov208_func_021BC3A4(key), 18));
        if (ov208_func_021BE840(icon) != 2) {
            ov208_func_021BE82C(icon, 1);
            ov208_func_021BE844(icon);
        }
        break;
    case 3:
        if (ov208_func_021BC4C8(W(0x418)) == 0 && ov208_func_021BC6C8(W(0x420)) == 0
            && ov208_func_021BDAD0(scene) == 2 && ov208_func_021BE840(icon) == 2) {
            ov208_func_021BDBA0(scene);
            ov208_func_021C2458(heap, p, key);
            ov208_func_021C1D0C(heap, p, key);
            *seq = 4;
        }
        break;
    case 4:
        if (W(0x84) == 0) {
            ov208_func_021BDC48(scene, 1);
            W(0x88) = 1;
            *seq = 5;
        }
        break;
    case 5:
        if (W(0x424) != 0) {
            ov208_func_021C1D24(heap, p, key);
            *seq = 6;
        } else {
            if (W(0x90) == 1)
                ov208_func_021C23BC(p);
            ov208_func_021C10B8(heap, p, key);
        }
        break;
    case 6:
        if (W(0x84) == 0) {
            ov208_func_021C24A4(heap, p, key);
            *seq = 7;
            ov208_func_021BC4E4(W(0x418));
            ov208_func_021BC6F8(W(0x420));
            ov208_func_021BE854(icon);
            if (W(0x424) == 2)
                ov208_func_021BDAE8(scene, 0);
        }
        break;
    case 7:
        ready = 0;
        if (ov208_func_021BC4C8(W(0x418)) == 0 && ov208_func_021BC6C8(W(0x420)) == 0
            && ov208_func_021BE840(icon) == 0) {
            if (W(0x424) == 2) {
                if (ov208_func_021BDAD0(scene) == 0)
                    ready = 1;
            } else {
                ready = 1;
            }
        }
        if (ready)
            *seq = 8;
        break;
    case 8:
        *seq = 9;
        ov208_func_021C252C(heap, p, key);
        ov208_func_021BC508(1, W(0x41c));
        break;
    case 9:
        ov208_func_021C0130(heap, p, key);
        func_0207D4B0(1, 0, 0);
        for (k = 0; k < 2; k++) {
            func_020403F4((u8)data_021C8618[k].bg);
            func_0203FCA0(data_021C8618[k].bg, &data_021C8618[k].tmpl, data_021C8618[k].type);
            func_020414AC(data_021C8618[k].bg);
            func_02040588(data_021C8618[k].bg, data_021C8618[k].on);
        }
        return 1;
    }
    if (*seq >= 2) {
        ov208_func_021BC99C(W(8));
        ov208_func_021C0968(heap, p, key);
        ov208_func_021C0A8C(heap, p, key);
    }
    ov208_func_021C1810(heap, p, key);
    ov208_func_021BC46C(W(0x418), W(0x41c));
    ov208_func_021BC678(W(0x420));
    ov208_func_021C0714(heap, p, key);
    return 0;
}
