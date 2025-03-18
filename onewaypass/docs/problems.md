# Usernames

The username problem goes deeper than just saving it or not.  
What about a user having multiple accounts at the same URI?  
Maybe the website saves them like eg. github.com/SchokiCoder.  
But that is not guaranteed. It could be a random string or a number or just not
visible at all.  
In that case the user would need to improvise, which leads to chaos.  
Some may save it as site.com/Username others as site.com_Username.  
Then some may forget how they named their key.  

# Solution 1
  
Maybe just encourage the user to always follow the scheme of site.com/Username?  
That would make the username effectively become a password... not quite the goal
of a password manager, right?  

# Solution 2

Most of the time, accounts are bound to an email address.  
Maybe just have a save file per email address, which saves all it's accounts,
by storing the URI.
This would create this scheme:  

- mail@server.org
	- hashed URI as key: encrypted PW as value

This would need a file for each email (duh), and one for non-email based logins.  
It also would change the CLI, since we have to allow creating new files,
deleting files, and having to pass a filename each time we want to do something
with already existing ones.  

## usage examples

`owp c mail1@gmail`
`owp create mail1@gmail`

Will create a file with given name.
Note: It is recommended to use one file per email address,
and one file for non-email based logins.
Then it will aks within stdin for a password to encrypt that file with,
which is optional.

`owp s mail1@gmail.com mastadon.social`
`owp set mail1@gmail.com mastadon.social`

Will add mastadon.social key to file of respective email, if not already there,
and set password to encryption of stdin input.
Sending SIGINT will cancel the entire operation.

`owp g mail1@gmail.com facebook.com`
`owp get mail1@gmail.com facebook.com`

Will get the the decrypted password for facebook.com,
if found in respective file of that email.
