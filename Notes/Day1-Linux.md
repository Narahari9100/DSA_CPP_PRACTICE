Linux

Introduction to Linux


uname -a      # Show system info
whoami        # Current user
pwd           # Print working directory
ls /          # List root directory


File & Directory Management

cd ~              # Go to home directory
cd /home          # Move into folder
ls -l             # List files (detailed)
mkdir test_dir    # Create directory
rmdir test_dir    # Remove empty directory
touch sample.txt  # Create empty file
rm sample.txt     # Remove file
cp file1 file2    # Copy file
mv file1 folder/  # Move file


Viewing & Editing Files

cat filename.txt      # View file contents
less filename.txt     # View page-by-page
head -n 5 filename.txt # First 5 lines
tail -n 5 filename.txt # Last 5 lines
nano filename.txt      # Edit a file

Permissions, Paths & Help

ls -l
chmod 755 filename
chmod +x script.sh
man ls
man chmod


Linux Command Power Pack


| Command   | Description                    | Example   |
| --------- | ------------------------------ | --------- |
| `cd ..`   | Go one directory up            | `cd ..`   |
| `cd -`    | Go back to previous directory  | `cd -`    |
| `cd /etc` | Go to a specific absolute path | `cd /etc` |
| `pwd`     | Show current path              | `pwd`     |
