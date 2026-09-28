# Relaunch after the 2026-09-28 01:xx session-limit cut

Every lane below was cut off mid-work by the account's session limit. Its previous run
left files in the tree that are NOT committed: sources in src/matched and src/pending,
shards in layout/matched/<region>, notes, and possibly half-edited files. Before any new
work:

1. List the files in your territory that are uncommitted (`git status --short` filtered
   to your region prefix or file names). Re-verify every source with `python tools/match.py
   one` using the command its header implies, and every shard in your territory with
   `python tools/match.py manifest --verify --shard <pkt>` twice (second pass rewrites
   nothing). A file whose header says EXACT but does not verify EXACT goes back to
   src/pending with its real verdict. Delete nothing that verifies.
2. Then continue the original task. Your report must list the salvaged files separately
   from new ones so the integrator can stage both.
