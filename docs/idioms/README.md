# Compiler idioms

One file per idiom, so that two agents working different packets never edit the
same file. `docs/MATCHING.md` carries a generated index of this directory;
`python tools/match.py idioms` rebuilds it and the integrator runs that once per
wave.

An idiom file is a thing this compiler does that is not obvious from the C, and
that cost somebody time. Keep it to one finding per file.

The format the index generator needs:

```markdown
# A short declarative title, the finding itself

summary: one or two sentences, which become the index line.

Found in: src/matched/unit_XXXXXXXX.c (0xADDRESS)

The body: what the original looks like, what C produces it, and what the
plausible wrong C produces instead.
```

The title is the first `# ` line and the summary is the first line starting
`summary:` plus any lines directly under it. The file name becomes the slug, so
keep it short and hyphenated.
