# v0.2.0

- arg `-e` which toggles encryption being used on target or not
- bother with post quantum encryption?

# v0.1.0

+ define goals.md

+ Instead of hardwiring encryption into the application, just call a hash and
  encrypt binary?
  `owp -t ~/.pw -h sha256sum -e "gpg -d" -g facebook.com`
                 ^            ^
	         |            -----------
                 |                      |
  calls `sha256sum` on "facebook.com"   |
                                        calls `gpg -d` on target_file
                                                    ^
                                      ---------------these suck
                                     \/
  `owp -t ~/.pw -h sha256sum -e "gpg -c"`
  
  this also sucks:
  `gpg -d my_file | owp -g $(echo "mastadon.social" | sha256sum)`
  
  this straight up doesn't work, pw needs to be piped into owp:
  `gpg -d my_file | owp -a $(echo "mastadon.social" | sha256sum)`

  JUST HARDWIRE the hash and encrypt algorithms!

- handle problems.md

- Regarding the extra fields (PIN, e-Mail, etc) just ask the user:
```
Do you want to add a field?
y
Name the field:
e-Mail
Value of that field:
gaben@valvesoftware.com
Do you want to add a field?
n
```

- add arg `-t TARGET_PATH`
- target file specificcation
- add entry add command `owp -a`
- add entry get command `owp -g`
- test removing read bit from target file and then using sudo
- add README.md
- add version print `owp -v`
- add about print `owp --about`
- add manpage
- set version to 0.1.0
