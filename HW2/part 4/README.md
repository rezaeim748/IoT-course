# HW2 – Part 4

## 📌 Question
Implement an IoT-based electronic voting system with one **central group** and multiple **voting groups**.

**Central group functions:**
- Register a new poll.  
- Create a new poll.  
- Add new options/candidates to a poll.  
- Start voting.  
- End voting.  
- Display results.  

**Voting group functions:**
- Receive poll data from the central group.  
- Cast votes and send them back.  

**Rules:**
- One group must be defined as the central group, the rest as voting groups.  
- Only the central group can create, start, and end polls.  
- Voting groups can only cast votes once per user.  
- At the end, results are shown as percentages of votes per option.  
- Example output:  
  ```
  Poll No.1: 1:50%, 2:10%, 3:40%
  ```

---

## 📝 Description
- The **central node** manages polls, candidates, and timing (start/finish).  
- The **voter nodes** receive poll information, display it, and allow casting votes.  
- Votes are sent back to the central node for counting.  
- At the end of voting, the central node calculates results and shows them in percentages.  
- All actions (poll creation, candidate addition, voting, results) are displayed on the Serial Monitor.  

This system demonstrates distributed IoT communication for managing an electronic voting process.  

---

## 🎥 Demonstration
https://github.com/user-attachments/assets/91341e92-99c7-485a-89b2-2b448f9e8d04
