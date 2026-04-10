alias bela-pull='rsync -avz --delete --exclude=".git" --exclude="build" root@bela.local:/root/Bela/projects/breathController/ ./'
alias bela-push='rsync -avz --delete --exclude="build" ./ root@bela.local:/root/Bela/projects/breathController/'
