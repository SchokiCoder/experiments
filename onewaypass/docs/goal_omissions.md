# config file

Instead just use a shell alias.
```Shell
# we dont wanna make it obvious what is using this file
alias owp=owp -t ~/.local/share/.totally_not_an_important_file
```
or
```Shell
# we removed read bit as well, sudo needed
alias owp=owp -t /root/owpfile -e
```
