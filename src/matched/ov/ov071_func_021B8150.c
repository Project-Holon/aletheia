/*
 * function: MONOLITH_TOOL_MENU_Destroy
 * address:  0x021B8150
 * packet:   pkt_ov071_021B8150
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MONOLITH_TOOL_MENU_FreeButtons  0x021B8270  thumb  ov071
 *   MONOLITH_TOOL_MENU_FreeCursor  0x021B82F0  thumb  ov071
 *   MONOLITH_TOOL_MENU_FreeWindow  0x021B83C0  thumb  ov071
 *   MONOLITH_TOOL_MENU_FreeBackgrounds  0x021B833C  thumb  ov071
 *   func_020315D4  0x020315D4  arm
 */

typedef struct {
    char pad[0x40];
    void *f40;
    void *f44;
} W;

typedef struct {
    int f0;
    struct {
        char pad[8];
        void *f8;
    } *f4;
} B;

typedef unsigned int   u32;
struct PrintSys;
struct Rec3;
struct Proc;
struct U16Vec;
int MONOLITH_TOOL_MENU_Destroy(void *a, int unused, B *b, W *w)
{
    extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
    extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
    extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
    extern void STRBUF_Delete(struct U16Vec *vec);
    extern void MONOLITH_TOOL_MENU_FreeButtons(unsigned char *p);
    extern void MONOLITH_TOOL_MENU_FreeCursor(void *p);
    extern void MONOLITH_TOOL_MENU_FreeWindow(void *p);
    extern void MONOLITH_TOOL_MENU_FreeBackgrounds(void);
    extern void func_020315D4(struct Proc *p);

    if (PRINTSYS_QUE_IsFinished(b->f4->f8) == 0) {
        return 0;
    }
    BG_SYS_SetSubVisiblePlanes(8);
    if (w->f40 != 0) {
        PRINTSYS_PrintStreamDelete(w->f40);
    }
    if (w->f44 != 0) {
        STRBUF_Delete(w->f44);
    }
    MONOLITH_TOOL_MENU_FreeButtons((unsigned char *)w);
    MONOLITH_TOOL_MENU_FreeCursor(w);
    MONOLITH_TOOL_MENU_FreeWindow(w);
    MONOLITH_TOOL_MENU_FreeBackgrounds();
    func_020315D4(a);
    return 1;
}
