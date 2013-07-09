	assert(diff && diff->repo);

	if (git_repository__cvar(&pi->oid_strlen, diff->repo, GIT_CVAR_ABBREV) < 0)
static char pick_suffix(int mode)
	else if (mode & 0100) //-V536
static int print_compact(
	old_suffix = pick_suffix(delta->old_file.mode);
	new_suffix = pick_suffix(delta->new_file.mode);
	git_buf_clear(pi->buf);
		pi->diff->strcomp(delta->old_file.path,delta->new_file.path) != 0)
		git_buf_printf(pi->buf, "%c\t%s%c -> %s%c\n", code,
		git_buf_printf(pi->buf, "%c\t%s%c (%o -> %o)\n", code,
		git_buf_printf(pi->buf, "%c\t%s%c\n", code, delta->old_file.path, old_suffix);
		git_buf_printf(pi->buf, "%c\t%s\n", code, delta->old_file.path);
	if (git_buf_oom(pi->buf))
			git_buf_cstr(pi->buf), git_buf_len(pi->buf), pi->payload))
		error = git_diff_foreach(diff, print_compact, NULL, NULL, &pi);
static int print_raw(
	git_buf_clear(pi->buf);
		pi->buf, ":%06o %06o %s... %s... %c",
		git_buf_printf(pi->buf, "%03u", delta->similarity);
	if (delta->status == GIT_DELTA_RENAMED || delta->status == GIT_DELTA_COPIED)
			pi->buf, "\t%s %s\n", delta->old_file.path, delta->new_file.path);
			pi->buf, "\t%s\n", delta->old_file.path ?
	if (git_buf_oom(pi->buf))
			git_buf_cstr(pi->buf), git_buf_len(pi->buf), pi->payload))
		error = git_diff_foreach(diff, print_raw, NULL, NULL, &pi);
static int print_oid_range(diff_print_info *pi, const git_diff_delta *delta)
		git_buf_printf(pi->buf, "index %s..%s %o\n",
			git_buf_printf(pi->buf, "new file mode %o\n", delta->new_file.mode);
			git_buf_printf(pi->buf, "deleted file mode %o\n", delta->old_file.mode);
			git_buf_printf(pi->buf, "old mode %o\n", delta->old_file.mode);
			git_buf_printf(pi->buf, "new mode %o\n", delta->new_file.mode);
		git_buf_printf(pi->buf, "index %s..%s\n", start_oid, end_oid);
	if (git_buf_oom(pi->buf))
static int print_patch_file(
	const char *oldpfx = pi->diff->opts.old_prefix;
	const char *newpfx = pi->diff->opts.new_prefix;
		 (pi->diff->opts.flags & GIT_DIFF_INCLUDE_UNTRACKED_CONTENT) == 0))

	git_buf_printf(pi->buf, "diff --git %s%s %s%s\n", oldpfx, delta->old_file.path, newpfx, delta->new_file.path);
	if (print_oid_range(pi, delta) < 0)
static int print_patch_hunk(
static int print_patch_line(
			diff, print_patch_file, print_patch_hunk, print_patch_line, &pi);

static int print_to_buffer_cb(
	const git_diff_delta *delta,
	const git_diff_range *range,
	char line_origin,
	const char *content,
	size_t content_len,
	void *payload)
{
	git_buf *output = payload;
	GIT_UNUSED(delta); GIT_UNUSED(range); GIT_UNUSED(line_origin);
	return git_buf_put(output, content, content_len);
}

			patch, print_patch_file, print_patch_hunk, print_patch_line, &pi);
	error = git_diff_patch_print(patch, print_to_buffer_cb, &output);