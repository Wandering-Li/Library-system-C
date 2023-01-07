# Library-system-C

This is a course work when I was a freshman in the university. I'm in a group of four, our task is to build a library system in 3 weeks. By that time, we only learned basdic C language, no any frame, no any concepts about "frontend" and "backend". But intuitively, we devide our work to "frontend" and "backend".I'm in charge of the "backend" with a nother classmate.  After weeks of hardworking, we built the library system with 3000 lines of code and got the best grade in the class.

By using basic C language, we creat an interface in the terminal, use keyboard as input. Each time the system launched, it read the file in the disk and store it in the RAM, while the system is exit(through the instraction in terminal), it write the data from RAM to the disk. Since by that time, what we have learned is just basic C language. This is the best we can do by using basic C language. And since the IDE we used by that time is completly outdated (VC6), it may have some bugs running in the vscode. Also the "project" is kind weak of showing the skills that I have. But i think that this 3000-line code could more or less shows that I'm capable for teamwork and "get things done" , as well as continous learning(too many bugs that we have encountred, and what can help us is just the Google.)


now let's see what the library system looks like.
My teammates built the interface in Chinese, and because this is interface showed in the terminal, It take efforts to align all the icon. Simply translate all the Chinese in to English will destroy the interface's design. So I choose to leave with it and roughly explan the features of the library system. Sorry for the inconvenience.

Overall, we built this system as if it will be used in the real life. We added all the features that we can come up with. 
The Admin can add books or delete books from the inventory, also admin can check all the record of borrowed book, or revise the book information.
The user can search the book they might want (supports fuzzy search), borrow book, return book, and check their profile to see how many books they have borrow and when should they return them. we set up a mechanism that each user can have three borrowed books at most, and each book have to be returned in one month. if a user have overdue book, they can not borrow new books until the user return the overdue book.


Now, let's launch the main.exe

![image](https://user-images.githubusercontent.com/86272490/211156682-24eddf9c-4631-472d-ad36-b021ac1e56c6.png)
1-register,2-login,0-exit


login interface
![image](https://user-images.githubusercontent.com/86272490/211156761-7e30c609-cad2-473c-8e0b-4c4e5605175d.png)
1.user login,2.adimn login, 3. login as a temporary visitor

By the way, we manage to detect the illegal input since some illegal input may crash the system. And when you put something wrong(for instance:wrong password):
![image](https://user-images.githubusercontent.com/86272490/211157145-b6ffa1b0-b313-4365-91e3-e21e2cf28cae.png)
"account or password wrong"
"Try again?(Y/N)"


user interface
![image](https://user-images.githubusercontent.com/86272490/211160267-9279137c-625f-4dfe-b79e-7a928cae2125.png)
1. book search
2. borrow
3. return
4. personal profile
0. logout
 
book search interface
![image](https://user-images.githubusercontent.com/86272490/211160367-6a056508-5f85-44b9-ac14-4574502e8d42.png)
1. search by book name 
2. search by category
3. search by author
4. search by publisher
0. return

let's search by book name and type"math"
the result shows:
![image](https://user-images.githubusercontent.com/86272490/211160513-2112cc51-d322-4612-a88e-45243a92abc1.png)

beside the number,the book name, category, publisher and author, it also shows howmany books the library have and howmany is available now.
to borrow the book, the procedure is about the same. just enter the number shows in the interface.


personal profile
![image](https://user-images.githubusercontent.com/86272490/211160674-3565de30-0567-41b9-b263-e85409e2d626.png)

it shows howmany book you have borrowed and when should you return them.






