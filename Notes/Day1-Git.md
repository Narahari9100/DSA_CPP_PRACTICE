Git

git init  -- Initialize Git

Connect your local repo to GitHub:

git remote add origin git@github.com:Narahari9100/DSA_CPP_PRACTICE.git


## Git Commands


| Action            | Command                       | Purpose                       |
| ----------------- | ----------------------------- | ----------------------------- |
| Check status      | `git status`                  | Shows tracked/untracked files |
| Track new files   | `git add file.cpp`            | Adds to staging area          |
| Commit changes    | `git commit -m "Message"`     | Saves snapshot locally        |
| Push to GitHub    | `git push origin branch_name` | Uploads commits               |
| View branches     | `git branch`                  | Shows branches                |
| Switch branch     | `git checkout branch_name`    | Change branch                 |
| Create new branch | `git checkout -b new_branch`  | Creates & switches            |
| Merge branches    | `git merge branch_name`       | Merge into current branch     |


git pull = fetch + merge

git fetch = get latest without merging

git merge = combine your work with others



git stash → temporarily save changes

git log --oneline --graph → visualize commit history

git tag v1.0 → mark release versions


## Advanced Branching & Git Workflow


# Create a new feature branch from current branch
git checkout -b feature/dsa_notes

# Merge changes from dev into current branch
git merge dev

# Rebase current branch onto main (clean linear history)
git rebase main

# Delete a local old branch
git branch -d old_branch

# Delete a remote branch from GitHub
git push origin --delete old_branch



# Pull, Fetch & Merge Conflicts


## 🔹 git fetch vs git pull

- git fetch  → gets changes from remote but doesn’t modify local files
- git pull   → fetch + merge automatically



- `git fetch` = **safe preview** of remote changes  
- `git pull` = **fetch + merge** (updates your branch automatically)  

Use `fetch` when you want to review first.  
Use `pull` when you’re confident to bring in all latest updates.

---

### 🧩 Example Practice

```bash
git fetch origin
git diff origin/main
git pull origin main
git merge origin/main





## Undoing Mistakes (Safety & Recovery)

git restore file.cpp           # discard local changes
git reset --soft HEAD~1        # undo last commit but keep changes
git reset --hard HEAD~1        # remove commit + changes
git revert <commit_id>         # undo pushed commit safely



## Git Logs, Tags & History


git log --oneline --graph --decorate
git show <commit_id>
git diff <commit_id1> <commit_id2>
git tag v1.0 -m "First stable release"
git push origin v1.0


## Git Stash (Save Work Temporarily)

git stash
git stash list
git stash apply stash@{0}
git stash drop stash@{0}


## Rebase, Squash & Clean History


git rebase -i HEAD~3
git commit --amend
git cherry-pick <commit_id>



```bash
# 1️⃣ Interactive Rebase — Edit last 3 commits
git rebase -i HEAD~3

# 2️⃣ Fix last commit message
git commit --amend -m "Updated commit message"

# 3️⃣ Pick one commit from another branch
git cherry-pick a1b2c3d


## 🧩 Advanced Git Notes (Professional Developer Level)


## 1️⃣ .gitignore
# Ignore unnecessary files
.vscode/
build/
*.o
*.out
*.log

# Practice:
echo "*.o" > .gitignore
git add .gitignore
git commit -m "Added .gitignore"

---

## 2️⃣ Git Reflog (Recover Lost Work)
git reflog                # View all recent HEAD changes
git checkout HEAD@{2}     # Move to a previous state

# Practice:
Delete branch accidentally -> restore using reflog

---

## 3️⃣ Git Hooks (Automation)
cd .git/hooks
nano pre-commit
#!/bin/bash
echo "Running pre-commit checks..."
clang-format -i *.cpp

chmod +x pre-commit

# Practice:
Try committing code -> pre-commit script runs automatically

---

## 4️⃣ Git Worktrees (Parallel Branch Work)
git worktree add ../feature_branch feature_branch
cd ../feature_branch
# Work independently without switching main branch

# Practice:
Open two folders and edit both branches simultaneously

---

## 5️⃣ Git Bisect (Find Bug Commit)
git bisect start
git bisect bad
git bisect good v1.0
# Git tests commits to find which introduced bug
git bisect reset

---

## 6️⃣ Git Aliases (Shortcut Commands)
git config --global alias.st status
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.cm "commit -m"

# Usage:
git st
git co main
git cm "Updated README"

---

## 7️⃣ Git Cleanup
git branch -d old_branch              # Delete local branch
git push origin --delete old_branch   # Delete remote branch
git prune                             # Clean up stale branches

