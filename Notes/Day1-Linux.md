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


## 🐧 Advanced Linux Notes (Developer Level)


# 🐧 Advanced Linux Notes (Developer Level)

## 1️⃣ Process Management
ps aux                 # List all running processes
top / htop             # Live system monitor
kill <PID>             # Stop process
pkill firefox          # Kill by name
jobs                   # Show background jobs
fg %1 / bg %1          # Bring job foreground/background

# Practice:
sleep 1000 &           # Run in background
jobs                   # Check jobs
kill %1                # Kill job

---

## 2️⃣ System Monitoring
free -h                # Check memory
uptime                 # System uptime
vmstat 1               # Monitor CPU & memory
iostat                 # Disk I/O stats

# Practice:
dd if=/dev/zero of=/tmp/testfile bs=1M count=100
top / vmstat 1         # Observe system

---

## 3️⃣ Disk & File System
df -h                  # Show disk usage
du -sh folder_name     # Folder size
lsblk                  # List disks/partitions
mount / umount         # Mount/unmount devices

# Practice:
du -sh /var/log        # Check log folder size

---

## 4️⃣ Networking
ip addr show           # Network interfaces
ping google.com        # Test connection
curl ifconfig.me       # Get public IP
netstat -tuln / ss -tuln # Open ports
scp file user@remote:/path # Copy file to remote

# Practice:
ping 8.8.8.8
curl example.com

---

## 5️⃣ Package & Service Management
sudo apt update        # Refresh packages
sudo apt install vim   # Install app
systemctl status ssh   # Check service
systemctl start ssh    # Start service
systemctl enable ssh   # Enable on boot

# Practice:
sudo apt install htop
htop

---

## 6️⃣ Users & Permissions
adduser testuser       # Create new user
passwd testuser        # Set password
groups testuser        # Check groups
sudo userdel testuser  # Remove user

# Practice:
su testuser            # Switch user

---

## 7️⃣ Environment Variables & Scripting
echo $PATH             # Show PATH
export VAR=value       # Set variable
env                    # Show environment

# Practice: create script
nano myscript.sh
#!/bin/bash
echo "Hello, $USER"
date

chmod +x myscript.sh
./myscript.sh
