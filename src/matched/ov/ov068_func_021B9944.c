/*
 * unit:     yes
 * function: OPTION_MENU_GetScreenSpriteActor, OPTION_MENU_GetScreenSpriteUnit, OPTION_MENU_GetScreenWindow, OPTION_MENU_RestartScreenBlink
 * address:  0x021B9944
 * packet:   pkt_ov068_021B9944
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four contiguous offset-thunks (0x021B9944..0x021B996C), each loading a
 * callee from its own literal pool and tail-calling it with the incoming
 * pointer adjusted.  Each callee is an unlabelled leaf reproduced EXACT under
 * src/matched/ov068_func_021BA018.c, _021BA020.c, _021B9BFC.c and
 * _021B9D58.c; those entries attest the pool-word sites (`matched`).
 *
 * symbols:
 *   OPTION_MENU_GetSpriteActor  0x021BA018  thumb  ov068
 *   OPTION_MENU_GetSpriteUnit  0x021BA020  thumb  ov068
 *   OPTION_MENU_GetGfxWindow  0x021B9BFC  thumb  ov068
 *   OPTION_MENU_RestartGfxBlink  0x021B9D58  thumb  ov068
 */

int OPTION_MENU_GetScreenSpriteActor(void *p, int i)
{
    int OPTION_MENU_GetSpriteActor(char *, int);
    return OPTION_MENU_GetSpriteActor((char *)p + 0x7c, i);
}

int OPTION_MENU_GetScreenSpriteUnit(void *p)
{
    int OPTION_MENU_GetSpriteUnit(int *p);
    return OPTION_MENU_GetSpriteUnit((int *)((char *)p + 0x7c));
}

int OPTION_MENU_GetScreenWindow(int *p, int i)
{
    int OPTION_MENU_GetGfxWindow(int *, int);
    return OPTION_MENU_GetGfxWindow(p, i);
}

void OPTION_MENU_RestartScreenBlink(char *p)
{
    void OPTION_MENU_RestartGfxBlink(char *);
    OPTION_MENU_RestartGfxBlink(p);
}
