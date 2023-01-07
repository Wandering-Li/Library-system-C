# Library-system-C

This is a course work when I was a freshman in the university. I'm in a group of four, our task is to build a library system in 3 weeks. By that time, we only learned basdic language C, no any frame, no any concepts about "frontend" and "backend". But intuitively, we devide our work to "frontend" and "backend".I'm in charge of the "backend" with a nother classmate.  After weeks of hardworking, we built the library system with 3000 lines of code and got the best grade in the class.

By using basic language C, we creat an interface in the terminal, use keyboard as input.

now let's see what the library system looks like.
My teammates built the interface in Chinese, and because this is interface showed in the terminal, It take efforts to align all the icon. Simply translate all the Chinese in to English will destroy the interface's design. So I choose to leave with it and roughly explan the features of the library system.

Overall, we built this system as if it will be used in the real life. We added all the features that we can come up with. 
The Admin can add books or delete books from the inventory, also admin can check all the record of borrowed book, or revise the book information.
The user can search the book they might want (supports fuzzy search), borrow book, return book, and check their profile to see how many books they have borrow and when should they return them. we set up a mechanism that each user can have three borrowed books at most, and each book have to be returned in two month. if a user have overdue book, they can not borrow new books until the user return the overdue book.


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





