# Explanation: Limitations and goals 

There are limitations, primary goals and secondary goals.  

Limitations describe what is __not allowed__ in the project/program.
Examples for that could be:  

- max. 3000 sloc
- C99, Linux code style
- libc only allowed dependency
- no incompatibility with FreeBSD, OpenBSD or Linux 

All __primary goals__ are to be implemented __before the final release__, unless
the implementation of a single goal proves to be too difficult or would come
with a too high cost such as a high increase of the sloc count.
The update implementing the last primary goal, becomes the final release update,
which in semantic versioning would be 1.0.0.  
Optimally the primary goals are documented as a roadmap.  

All __secondary goals__ are to be assigned __after the final release__.  
Optimally the secondary goals are documented as a roadmap,
starting where the primary goal-roadmap ended.  

# Limitations

- Rust, suckless code style for Rust see
  [rshui/docs/code_style.md](https://github.com/SchokiCoder/rshui/blob/main/docs/code_style.md).
- max. 2000 sloc in Rust
- max. 200 sloc for build system (eg. Cargo.toml)
- see Anti-features

# Anti-features

The following features must NOT be implemented:

- a "print all" command, that prints all entries
  Since URL's are hashed irreversibly that shouldn't be possible anyways.
  Still here just to make sure.

# Roadmap

## v0.1.0 basics

### usage

`owp -a`  
Prompts to put in URI and then password (dont echo), saves hash of URI and
reversable hash from password in file.  
If URL already exists, let user confirm the overwrite.  

`owp -g URI`  
Encrypts URI, tries to find key in file (path from cfg).

### target_file

File in which irreversibly hashed URI's are mapped to reversibly hashed
passwords.  
The reverse hash password is the plain URI itself which should only be known by
the user.  
Incourage the user to remove read bits from target file and as such additionally
require sudo/doas to even open the file.  

## v0.2.0 optional hardening

- add config option to use encrypted target_files only
  Upon any given command, prompt for the file password and then continue as normal.
  Newly created target files will be encrypted.
  Old unencrypted ones will be ignored with a warning prompt or maybe add a
  convert command/prompt?

## v1.0.0 Clean up

- intensive pen testing and analysis
- cargo crate release
- `--add` alias for `-a`
- `--get` alias for `-g`
