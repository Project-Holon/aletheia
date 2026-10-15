/*
 * function: CARDi_NotifyEvent
 * address:  0x02076100
 * packet:   pkt_02076100
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_NotifyEvent (libcard.TWL.HYB.a card_hook.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   cardi_hook_state  0x02150720  data
 *   CARDiHookChain  0x02150720  data
 */
typedef unsigned long u32;
typedef struct CARDHookContext
{
  struct CARDHookContext *next;
  void *userdata;
  void (*callback)(void *userdata, u32 event, void *arg);
} CARDHookContext;
extern CARDHookContext *CARDiHookChain;
extern struct 
{
  CARDHookContext *chain;
} cardi_hook_state;
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
void CARDi_NotifyEvent(u32 event, void *arg)
{
    u32 bak = OS_DisableInterrupts();
    CARDHookContext **pp = &CARDiHookChain;
    CARDHookContext *hook = cardi_hook_state.chain;

    while (hook)
    {
        if (hook->callback)
        {
            (*hook->callback)(hook->userdata, event, arg);
        }
        if (*pp == hook)
        {
            pp = &(*pp)->next;
        }
        hook = *pp;
    }
    (void)OS_RestoreInterrupts(bak);
}
